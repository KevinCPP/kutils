#include <stdlib.h>
#include <string.h>

#include "ku_string.h"

// forward decl for string
typedef struct ku_string {
    char* data;
    size_t length;
    size_t capacity;
} ku_string;

// create and destroy
ku_string* ku_string_create() {
    ku_string* str = (ku_string*)malloc(sizeof(ku_string));
    str->data = (char*)malloc(sizeof(char));
    str->data[0] = '\0';
    str->length = 0;
    str->capacity = 0;
    return str;
}

void ku_string_destroy(ku_string** str) {
    if (str == NULL || *str == NULL)
        return;

    free((*str)->data);
    free(*str);
    *str = NULL;
}

static int ku_string_ensure_capacity(ku_string* str, size_t new_length) {
    // nothing to do if the new length fits within the capacity
    if (new_length < str->capacity)
        return 0;
    
    // here, we double the new capacity, or start it at 2 if
    // no memory has been allocated yet.
    size_t new_cap = str->capacity ? str->capacity << 1 : 2;
    // if that still isn't enough, we keep doubling the size
    // until we reach a capacity that can fit all of the new
    // elements
    while (new_cap < new_length) {
        new_cap <<= 1;
        // check for overflow error
        if (new_cap < str->capacity)
            return -1;
    }
    
    // finally, reserve the new capacity and return status
    int success = ku_string_reserve(str, new_cap);
    return success;
}

// access and modify
int ku_string_set(ku_string* str, size_t index, char element) {
    if (str == NULL || str->length <= index) {
        return -1;
    }

    str->data[index] = element;
    return 0;
}

int ku_string_append(ku_string* str, char* arr, size_t len) {
    if (str == NULL || arr == NULL) {
        return -1;
    }

    if (len == 0) {
        return 0;
    }

    if (ku_string_ensure_capacity(str, str->length + len) != 0) {
        return -1;
    }
    
    if (str->data[str->length] != '\0') {
        return -1;
    }

    size_t offset = (str->length * sizeof(char)) - 1;
    memcpy(str->data + offset, arr, len * sizeof(char));
    str->length += len;
    str->data[str->length] = '\0';
    return 0;
}

char ku_string_get(const ku_string* str, size_t index) {
    if (str == NULL || str->length <= index)
        return '\0';

    return str->data[index];

    return '\0';
}

int ku_string_delete(ku_string* str, size_t index) {
    
    return 0;
}

int ku_string_reserve(ku_string* str, size_t size) { 
    return 0;
}

int ku_string_push(ku_string* str, char element) {
    return 0;
}

size_t ku_string_capacity(const ku_string* str) {
    
    return 0;
}

size_t ku_string_length(const ku_string* str) {
    
    return 0;
}

char* ku_string_get_data_ptr(ku_string* str) {
    
    return NULL;
}

char ku_string_pop(ku_string* str) {
    
    return 0;
}
