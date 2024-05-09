#ifndef DEFINES_H_
#define DEFINES_H_

// Includes
#include <stdbool.h>
#include <stdlib.h>

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

// String
typedef struct {
    const char* start;
    usize length;
} String;

// ------ Macros ------
// Array length
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof((array)[0]))

// Assert for enums (checks if a array has the same amount of elements as the enum)
#define ASSERT_ENUM_ELEMENT_COUNT(sarray, max) typedef char assert_sizeof_##max[(sizeof(sarray)/sizeof((sarray)[0]) == (max)) ? 1 : -1]

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
