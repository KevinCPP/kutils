#include "sorting.h"

void sort_int(int* input_array, size_t size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j != 0; j--) {
            if (input_array[j] < input_array[j-1]) {
                int temp = input_array[j];
                input_array[j] = input_array[j-1];
                input_array[j-1] = temp;
            } else {
                break;
            }
        }
    }
}
