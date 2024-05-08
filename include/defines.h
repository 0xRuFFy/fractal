#ifndef DEFINES_H_
#define DEFINES_H_

// Includes
#include <stdbool.h>

// ------ Types ------
// unsigned integer types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned long usize;

// integer types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long i64;

// floating point types
typedef float f32;
typedef double f64;

// ------ Macros ------
// Array length
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

// Min and max
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((b) < (a) ? (a) : (b))

// Swap
#define swap(a, b)          \
    do {                    \
        typeof(a) temp = a; \
        a = b;              \
        b = temp;           \
    } while (0)

// Bit manipulation
#define setBit(byte, bit) ((byte) |= (1 << (bit)))
#define clearBit(byte, bit) ((byte) &= ~(1 << (bit)))
#define toggleBit(byte, bit) ((byte) ^= (1 << (bit)))

#endif /* DEFINES_H_ */
