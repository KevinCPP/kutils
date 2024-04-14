#ifndef VEC_H
#define VEC_H

#include <stddef.h>

// dynamic array, "vec" declaration
typedef struct ku_vec ku_vec;

// create and destroy a vec
ku_vec* ku_vec_create(size_t elem_size);
void ku_vec_destroy(ku_vec** vec);

// access and modify
int    ku_vec_set(ku_vec* vec, size_t index, void* element);  // set an element at the given index
int    ku_vec_append(ku_vec* vec, void* arr, size_t len);     // append an array of elements to the vector
void*  ku_vec_get(const ku_vec* vec, size_t index);           // get an element at index
int    ku_vec_reserve(ku_vec* vec, size_t size);              // reserve a capacity for the vector
int    ku_vec_push(ku_vec* vec, void* element);               // add a new element to the vector
size_t ku_vec_capacity(const ku_vec* vec);                    // retrieve the capacity of the vector
size_t ku_vec_length(const ku_vec* vec);                      // retrieve the length of the vector
void*  ku_vec_get_data_ptr(ku_vec* vec);                      // get the pointer to the underlying data array
void*  ku_vec_pop(ku_vec* vec);                               // pop the top element off the vector

#endif
