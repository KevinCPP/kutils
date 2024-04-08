#include "sorting.h"
#include <stdio.h>

int cmp_int(void* a, void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]) {
    int arr[10] = {8, 5, 9, 8, 6, 7, 5, 3, 0, 9};

    ku_insertionsort((void*)arr, 10, sizeof(int), cmp_int);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
