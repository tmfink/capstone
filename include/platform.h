/* Capstone Disassembly Engine */
/* By Axel Souchet & Nguyen Anh Quynh, 2014 */

#ifndef CAPSTONE_PLATFORM_H
#define CAPSTONE_PLATFORM_H

// handle C99 issue (for pre-2013 VisualStudio)
#if !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__MINGW64__) && (defined (WIN32) || defined (WIN64) || defined (_WIN32) || defined (_WIN64))
// MSVC

#ifdef CAPSTONE_THREAD_SAFE
// Only required if we need threading
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define CAPSTONE_THREAD_WINTHREAD
#endif

// stdbool.h
#if (_MSC_VER < 1800) || defined(_KERNEL_MODE)
// this system does not have stdbool.h
#ifndef __cplusplus
typedef unsigned char bool;
#define false 0
#define true 1
#endif

#else
// VisualStudio 2013+ -> C99 is supported
#include <stdbool.h>
#endif

#else
// not MSVC -> C99 is supported
#include <stdbool.h>

#ifdef CAPSTONE_THREAD_SAFE
#include <pthread.h>
#define CAPSTONE_THREAD_PTHREAD
#endif

#endif

// Platform-independent threading interface

#ifdef CAPSTONE_THREAD_WINTHREAD
#define _DECLARE_ONCE_VAR(once_var) static INIT_ONCE once_var = INIT_ONCE_STATIC_INIT
#define _ONCE_SYNC_CALL(once_var, init_routine) InitOnceExecuteOnce(&once_var, init_routine, NULL, NULL)
#endif

#ifdef CAPSTONE_THREAD_PTHREAD
#define _DECLARE_ONCE_VAR(once_var) static pthread_once_t once_var = PTHREAD_ONCE_INIT
#define _ONCE_SYNC_CALL(once_var, init_routine) pthread_once(&once_var, init_routine)
#endif

#ifndef CAPSTONE_THREAD_SAFE
#define _DECLARE_ONCE_VAR(once_var) static bool once_var = false
#define _ONCE_SYNC_CALL(once_var, init_routine) do { \
	if (once_var) { \
		return; \
	} \
	init_routine(); \
	once_var = true; \
	} while(0)
#endif

#define ONCE_SYNC_FUNC(once_var, init_routine) do { \
	_DECLARE_ONCE_VAR(once_var); \
	_ONCE_SYNC_CALL(once_var, init_routine); \
	} while(0)

// handle C99 issue (for pre-2013 VisualStudio)
#if defined(CAPSTONE_HAS_OSXKERNEL) || (defined(_MSC_VER) && (_MSC_VER <= 1700 || defined(_KERNEL_MODE)))
// this system does not have inttypes.h

#if defined(_MSC_VER) && (_MSC_VER < 1600 || defined(_KERNEL_MODE))
// this system does not have stdint.h
typedef signed char  int8_t;
typedef signed short int16_t;
typedef signed int   int32_t;
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef signed long long   int64_t;
typedef unsigned long long uint64_t;

#define INT8_MIN         (-127i8 - 1)
#define INT16_MIN        (-32767i16 - 1)
#define INT32_MIN        (-2147483647i32 - 1)
#define INT64_MIN        (-9223372036854775807i64 - 1)
#define INT8_MAX         127i8
#define INT16_MAX        32767i16
#define INT32_MAX        2147483647i32
#define INT64_MAX        9223372036854775807i64
#define UINT8_MAX        0xffui8
#define UINT16_MAX       0xffffui16
#define UINT32_MAX       0xffffffffui32
#define UINT64_MAX       0xffffffffffffffffui64
#endif

#define __PRI_8_LENGTH_MODIFIER__ "hh"
#define __PRI_64_LENGTH_MODIFIER__ "ll"

#define PRId8         __PRI_8_LENGTH_MODIFIER__ "d"
#define PRIi8         __PRI_8_LENGTH_MODIFIER__ "i"
#define PRIo8         __PRI_8_LENGTH_MODIFIER__ "o"
#define PRIu8         __PRI_8_LENGTH_MODIFIER__ "u"
#define PRIx8         __PRI_8_LENGTH_MODIFIER__ "x"
#define PRIX8         __PRI_8_LENGTH_MODIFIER__ "X"

#define PRId16        "hd"
#define PRIi16        "hi"
#define PRIo16        "ho"
#define PRIu16        "hu"
#define PRIx16        "hx"
#define PRIX16        "hX"

#if defined(_MSC_VER) && _MSC_VER <= 1700
#define PRId32        "ld"
#define PRIi32        "li"
#define PRIo32        "lo"
#define PRIu32        "lu"
#define PRIx32        "lx"
#define PRIX32        "lX"
#else	// OSX
#define PRId32        "d"
#define PRIi32        "i"
#define PRIo32        "o"
#define PRIu32        "u"
#define PRIx32        "x"
#define PRIX32        "X"
#endif

#if defined(_MSC_VER) && _MSC_VER <= 1700
// redefine functions from inttypes.h used in cstool
#define strtoull _strtoui64
#endif

#define PRId64        __PRI_64_LENGTH_MODIFIER__ "d"
#define PRIi64        __PRI_64_LENGTH_MODIFIER__ "i"
#define PRIo64        __PRI_64_LENGTH_MODIFIER__ "o"
#define PRIu64        __PRI_64_LENGTH_MODIFIER__ "u"
#define PRIx64        __PRI_64_LENGTH_MODIFIER__ "x"
#define PRIX64        __PRI_64_LENGTH_MODIFIER__ "X"

#else
// this system has inttypes.h by default
#include <inttypes.h>
#endif

#endif
