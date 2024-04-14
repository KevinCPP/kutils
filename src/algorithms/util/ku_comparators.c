#include "ku_comparators.h"

int ku_char_cmp(const void* a, const void* b) {
    char aa = *(const char*)a;
    char bb = *(const char*)b;
    return (aa > bb) - (aa < bb);
}

int ku_signed_char_cmp(const void* a, const void* b) {
    signed char aa = *(const signed char*)a;
    signed char bb = *(const signed char*)b;
    return (aa > bb) - (aa < bb);
}

int ku_unsigned_char_cmp(const void* a, const void* b) {
    unsigned char aa = *(const unsigned char*)a;
    unsigned char bb = *(const unsigned char*)b;
    return (aa > bb) - (aa < bb);
}

int ku_wchar_cmp(const void* a, const void* b) {
    wchar_t aa = *(const wchar_t*)a;
    wchar_t bb = *(const wchar_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_short_cmp(const void* a, const void* b) {
    short aa = *(const short*)a;
    short bb = *(const short*)b;
    return (aa > bb) - (aa < bb);
}

int ku_unsigned_short_cmp(const void* a, const void* b) {
    unsigned short aa = *(const unsigned short*)a;
    unsigned short bb = *(const unsigned short*)b;
    return (aa > bb) - (aa < bb);
}

int ku_int_cmp(const void* a, const void* b) {
    int aa = *(const int*)a;
    int bb = *(const int*)b;
    return (aa > bb) - (aa < bb);
}

int ku_unsigned_int_cmp(const void* a, const void* b) {
    unsigned int aa = *(const unsigned int*)a;
    unsigned int bb = *(const unsigned int*)b;
    return (aa > bb) - (aa < bb);
}

int ku_long_cmp(const void* a, const void* b) {
    long aa = *(const long*)a;
    long bb = *(const long*)b;
    return (aa > bb) - (aa < bb);
}

int ku_unsigned_long_cmp(const void* a, const void* b) {
    unsigned long aa = *(const unsigned long*)a;
    unsigned long bb = *(const unsigned long*)b;
    return (aa > bb) - (aa < bb);
}

int ku_long_long_cmp(const void* a, const void* b) {
    long long aa = *(const long long*)a;
    long long bb = *(const long long*)b;
    return (aa > bb) - (aa < bb);
}

int ku_unsigned_long_long_cmp(const void* a, const void* b) {
    unsigned long long aa = *(const unsigned long long*)a;
    unsigned long long bb = *(const unsigned long long*)b;
    return (aa > bb) - (aa < bb);
}

int ku_int8_cmp(const void* a, const void* b) {
    int8_t aa = *(const int8_t*)a;
    int8_t bb = *(const int8_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_uint8_cmp(const void* a, const void* b) {
    uint8_t aa = *(const uint8_t*)a;
    uint8_t bb = *(const uint8_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_int16_cmp(const void* a, const void* b) {
    int16_t aa = *(const int16_t*)a;
    int16_t bb = *(const int16_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_uint16_cmp(const void* a, const void* b) {
    uint16_t aa = *(const uint16_t*)a;
    uint16_t bb = *(const uint16_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_int32_cmp(const void* a, const void* b) {
    int32_t aa = *(const int32_t*)a;
    int32_t bb = *(const int32_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_uint32_cmp(const void* a, const void* b) {
    uint32_t aa = *(const uint32_t*)a;
    uint32_t bb = *(const uint32_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_int64_cmp(const void* a, const void* b) {
    int64_t aa = *(const int64_t*)a;
    int64_t bb = *(const int64_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_uint64_cmp(const void* a, const void* b) {
    uint64_t aa = *(const uint64_t*)a;
    uint64_t bb = *(const uint64_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_size_cmp(const void* a, const void* b) {
    size_t aa = *(const size_t*)a;
    size_t bb = *(const size_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_ptrdiff_cmp(const void* a, const void* b) {
    ptrdiff_t aa = *(const ptrdiff_t*)a;
    ptrdiff_t bb = *(const ptrdiff_t*)b;
    return (aa > bb) - (aa < bb);
}

int ku_float_cmp(const void* a, const void* b) {
    float aa = *(const float*)a;
    float bb = *(const float*)b;
    return (aa > bb) - (aa < bb);
}

int ku_double_cmp(const void* a, const void* b) {
    double aa = *(const double*)a;
    double bb = *(const double*)b;
    return (aa > bb) - (aa < bb);
}

int ku_long_double_cmp(const void* a, const void* b) {
    long double aa = *(const long double*)a;
    long double bb = *(const long double*)b;
    return (aa > bb) - (aa < bb);
}
