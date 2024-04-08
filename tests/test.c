#include "sorting.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int arr[10] = {8, 5, 9, 8, 6, 7, 5, 3, 0, 9};
    sort_int(arr, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
