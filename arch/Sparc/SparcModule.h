/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2018 */

#ifndef CS_SPARC_MODULE_H
#define CS_SPARC_MODULE_H

#include "../../utils.h"

cs_err Sparc_global_init(cs_struct *ud);
cs_err Sparc_option(cs_struct *handle, cs_opt_type type, size_t value);
void Sparc_destroy(cs_struct *handle);

#endif
