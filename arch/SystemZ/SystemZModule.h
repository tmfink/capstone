/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2018 */

#ifndef CS_SYSTEMZ_MODULE_H
#define CS_SYSTEMZ_MODULE_H

#include "../../utils.h"

cs_err SystemZ_global_init(cs_struct *ud);
cs_err SystemZ_option(cs_struct *handle, cs_opt_type type, size_t value);
void SystemZ_destroy(cs_struct *handle);

#endif
