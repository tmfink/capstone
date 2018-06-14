/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2018 */

#ifndef CS_XCORE_MODULE_H
#define CS_XCORE_MODULE_H

#include "../../utils.h"

cs_err XCore_global_init(cs_struct *ud);
cs_err XCore_option(cs_struct *handle, cs_opt_type type, size_t value);
void XCore_destroy(cs_struct *handle);

#endif
