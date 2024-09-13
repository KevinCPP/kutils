#ifndef STRING_H
#define STRING_H

#include <stddef.h>

// forward decl for string
typedef struct ku_string ku_string;

// create and destroy
ku_string* ku_string_create();
void ku_string_destroy(ku_string** str);

// access and modify
int     ku_string_set(ku_string* str, size_t index, char element);
int     ku_string_append(ku_string* str, char* arr, size_t len);
char    ku_string_get(const ku_string* str, size_t index);
int     ku_string_delete(ku_string* str, size_t index);
int     ku_string_reserve(ku_string* str, size_t size);
int     ku_string_push(ku_string* str, char element);
size_t  ku_string_capacity(const ku_string* str);
size_t  ku_string_length(const ku_string* str);
char*   ku_string_get_data_ptr(ku_string* str);
char    ku_string_pop(ku_string* str);

#endif
