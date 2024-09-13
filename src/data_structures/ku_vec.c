#include <stdlib.h>
#include <string.h>

#include "ku_vec.h"

// ku_vec underlying implementation
typedef struct ku_vec {
    void *data;
    size_t esize;
    size_t length;
    size_t capacity;
} ku_vec;

// create a vector
ku_vec* ku_vec_create(size_t elem_size) {
    ku_vec* v = (ku_vec*)malloc(sizeof(ku_vec));
    v->data = NULL;
    v->esize = elem_size;
    v->length = 0;
    v->capacity = 0;
    return v;
}

// destroy a vector
void ku_vec_destroy(ku_vec** vec) {
    // guard against null pointers
    if (vec == NULL || *vec == NULL)
        return;
    
    // free the data
    free((*vec)->data);
    // free the vec itself
    free(*vec);
    // set the caller's pointer to NULL
    *vec = NULL;
}

static int ku_vec_ensure_capacity(ku_vec* vec, size_t new_length) {
    if (new_length < vec->capacity)
        return 0;

    // keep increasing new capacity by powers of 2 until
    // it has enough space for all of the new elements.
    size_t new_cap = vec->capacity ? vec->capacity << 1 : 2;
    while (new_cap < new_length) {
        new_cap <<= 1;
        
        // check for an overflow
        if (new_cap < vec->capacity)
            return -1;
    }
    int success = ku_vec_reserve(vec, new_cap);
    return success;
}

// set an element at index
int ku_vec_set(ku_vec* vec, size_t index, void* element) {
    if (vec == NULL || element == NULL || vec->length <= index) {
        return -1;
    }

    char* data = (char*)vec->data;
    size_t offset = index * vec->esize;
    memcpy(data + offset, element, vec->esize);

    return 0;
}

// append elements to the vector
int ku_vec_append(ku_vec* vec, void* arr, size_t len) {
    if (vec == NULL || arr == NULL)
        return -1;

    if (len == 0)
        return 0;
    
    if (ku_vec_ensure_capacity(vec, vec->length + len) != 0) {
        return -1;
    }

    // calculate offset to copy input data into the vector's data array
    char* vec_data = (char*)vec->data;
    char* input_data = (char*)arr;
    size_t offset = vec->length * vec->esize;
    
    // success, copy the data and update length
    memcpy(vec_data + offset, input_data, len * vec->esize);
    vec->length += len;
    return 0;
}

// get element at index
void* ku_vec_get(const ku_vec* vec, size_t index) {
    if(vec == NULL || vec->length <= index)
        return NULL;

    char* data = (char*)vec->data;
    size_t offset = index * vec->esize;
    
    void* out = malloc(vec->esize);
    memcpy(out, data + offset, vec->esize);
    return out;
}

// allocate at least size * element_size bytes for the vector
int ku_vec_reserve(ku_vec* vec, size_t size) {
    if (vec == NULL)
        return -1;
    
    // if size is less than the current capacity,
    // then enough space has already been reserved
    if (size <= vec->capacity)
        return 0;
    
    // allocate size * esize bytes
    size_t new_cap = size;
    void* new_data = realloc(vec->data, new_cap * vec->esize);
    if (new_data == NULL)
        return -1;
    
    vec->data = new_data;
    vec->capacity = new_cap;
    
    // success
    return 0;
}

// push an individual element onto the vector
int ku_vec_push(ku_vec* vec, void* element) {
    if (vec == NULL || element == NULL)
        return -1;
    
    // check if the vector needs to be expanded
    ku_vec_ensure_capacity(vec, vec->length + 1);

    // calculate where to copy new element
    char* data = (char*)vec->data;
    memcpy(data + (vec->length * vec->esize), element, vec->esize);
    vec->length += 1;
    
    // success
    return 0;
}

// get vector capacity
size_t ku_vec_capacity(const ku_vec* vec) {
    if (vec == NULL)
        return 0;

    return vec->capacity;
}

// get vector length
size_t ku_vec_length(const ku_vec* vec) {
    if (vec == NULL)
        return 0;

    return vec->length;
}

// get a pointer to the data
void* ku_vec_get_data_ptr(ku_vec* vec) {
    if (vec == NULL)
        return NULL;

    return vec->data;
}

// pop last element off
void* ku_vec_pop(ku_vec* vec) {
    // return null if no valid element to pop
    if (vec == NULL || vec->length == 0)
        return NULL;
    
    void* out = ku_vec_get(vec, vec->length-1);
    vec->length -= 1;
    return out;
}
