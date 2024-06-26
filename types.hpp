#ifndef SB_LIB_TYPES_HPP
#define SB_LIB_TYPES_HPP

// TODO: have macros that probe the size of primitive integers and
// defines these accordingly

namespace SB_LIB {

typedef signed char int8;
typedef short int16;
typedef long int32;
typedef long long int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef long long mlen; // TODO: 32 if 32bit, 64 if 64bit

}
#endif