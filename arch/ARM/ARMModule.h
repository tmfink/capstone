/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2018 */

#ifndef CS_ARM_MODULE_H
#define CS_ARM_MODULE_H

#include "../../utils.h"

cs_err ARM_global_init(cs_struct *ud);
cs_err ARM_option(cs_struct *handle, cs_opt_type type, size_t value);
void ARM_destroy(cs_struct *handle);

#endif
