/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2018 */

#ifndef CS_AARCH64_MODULE_H
#define CS_AARCH64_MODULE_H

#include "../../utils.h"

cs_err AArch64_global_init(cs_struct *ud);
cs_err AArch64_option(cs_struct *handle, cs_opt_type type, size_t value);
void AArch64_destroy(cs_struct *handle);

#endif
