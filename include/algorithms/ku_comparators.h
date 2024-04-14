#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//////// integer type comparators ////////

// char, signed char, and unsigned char are each unique types. The signed char
// has a range of -128 to 127, the unsigned char has a range of 0 to 255, and
// the char type has the same range as either signed char or unsigned char
// depending on the system.
int ku_char_cmp(const void* a, const void* b);            
int ku_signed_char_cmp(const void* a, const void* b);
int ku_unsigned_char_cmp(const void* a, const void* b);

int ku_wchar_cmp(const void* a, const void* b);

int ku_short_cmp(const void* a, const void* b);
int ku_unsigned_short_cmp(const void* a, const void* b);
int ku_int_cmp(const void* a, const void* b);
int ku_unsigned_int_cmp(const void* a, const void* b);
int ku_long_cmp(const void* a, const void* b);
int ku_unsigned_long_cmp(const void* a, const void* b);
int ku_long_long_cmp(const void* a, const void* b);
int ku_unsigned_long_long_cmp(const void* a, const void* b);

int ku_int8_cmp(const void* a, const void* b);
int ku_uint8_cmp(const void* a, const void* b);
int ku_int16_cmp(const void* a, const void* b);
int ku_uint16_cmp(const void* a, const void* b);
int ku_int32_cmp(const void* a, const void* b);
int ku_uint32_cmp(const void* a, const void* b);
int ku_int64_cmp(const void* a, const void* b);
int ku_uint64_cmp(const void* a, const void* b);
int ku_size_cmp(const void* a, const void* b);
int ku_ptrdiff_cmp(const void* a, const void* b);
int ku_bool_cmp(const void* a, const void* b);

//////// floating point type comparators ////////
int ku_float_cmp(const void* a, const void* b);
int ku_double_cmp(const void* a, const void* b);
int ku_long_double_cmp(const void* a, const void* b);

#endif
