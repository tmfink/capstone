# Capstone Python bindings, by Fotis Loukos <me@fotisl.com>

import ctypes, copy
from .tms320c64x_const import *

# define the API
class TMS320C64xOpMem(ctypes.Structure):
    _fields_ = (
        ('base', ctypes.c_int),
        ('disp', ctypes.c_uint32),
        ('unit', ctypes.c_uint8),
        ('scaled', ctypes.c_bool),
        ('disptype', ctypes.c_uint),
        ('direction', ctypes.c_uint),
        ('modify', ctypes.c_uint),
    )

class TMS320C64xOpValue(ctypes.Union):
    _fields_ = (
        ('reg', ctypes.c_uint),
        ('imm', ctypes.c_int32),
        ('mem', TMS320C64xOpMem),
    )

class TMS320C64xOp(ctypes.Structure):
    _fields_ = (
        ('type', ctypes.c_uint),
        ('value', TMS320C64xOpValue),
    )

    @property
    def imm(self):
        return self.value.imm

    @property
    def reg(self):
        return self.value.reg

    @property
    def mem(self):
        return self.value.mem

class CsTMS320C64x(ctypes.Structure):
    _fields_ = (
        ('op_count', ctypes.c_uint8),
        ('operands', TMS320C64xOp * 8),
        ('condition_reg', ctypes.c_uint),
        ('funit_unit', ctypes.c_uint),
        ('funit_side', ctypes.c_uint8),
        ('funit_crosspath', ctypes.c_int8),
        ('condition_zero', ctypes.c_bool),
        ('parallel', ctypes.c_int8),
    )

def get_arch_info(a):
    return (a.condition_reg, a.funit_unit, a.funit_side, a.funit_crosspath,
            a.condition_zero, a.parallel, copy.deepcopy(a.operands[:a.op_count]))
