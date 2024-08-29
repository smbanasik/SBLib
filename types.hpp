#ifndef SB_LIB_TYPES_HPP
#define SB_LIB_TYPES_HPP

// TODO: have macros that probe the size of primitive integers and
// defines these accordingly
namespace SB_LIB {

#ifdef SB_LIB_USE_STDINT
#include <stdint.h>
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef uint64_t mlen;
#else

typedef signed char int8;
typedef unsigned char uint8;
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _MSVC_LANG
typedef short int16;
typedef long int32;
typedef unsigned short uint16;
typedef unsigned long uint32;

#ifdef _WIN64
#define SB_LIB_PTR_SIZE 8
#else
#define SB_LIB_PTR_SIZE 4
#endif
#endif

#ifdef __GNUC__

#if __SIZEOF_SHORT__ == 2
typedef short int16;
typedef unsigned short uint16;
#endif
#if __SIZEOF_INT__ == 4
typedef int int32;
typedef unsigned int uint32;
#elif __SIZEOF_LONG == 4
typedef long int32;
typedef unsigned long uint32;
#endif

#if __SIZEOF_POINTER__ == 8
#define SB_LIB_PTR_SIZE 8
#else
#define SB_LIB_PTR_SIZE 4
#endif
#endif
#endif

#ifdef SB_LIB_PTR_SIZE == 8
typedef uint64 mlen;
typedef int64 ptr_diff;
#else
typedef uint32 mlen;
typedef int32 ptr_diff; 
#endif

#undef SB_LIB_PTR_SIZE

}
#endif