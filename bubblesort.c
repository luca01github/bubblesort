#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int a[],
                int n,
                int (*ascending_or_descending)(int elem1, int elem2)) {
    for (int pass = 1; pass < n; pass++) {
        int swapped = 0;
        for (int count = 0; count < n - 1; count++) {
            if ((*ascending_or_descending)(a[count], a[count + 1])) {
                swap(&a[count], &a[count + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int ascending(int elem1, int elem2) { return elem1 > elem2; }

int descending(int elem1, int elem2) { return elem1 < elem2; }

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%-4d", a[i]);
        if (i % 10 == 9) {
            putchar('\n');
        }
    }
    putchar('\n');
}

int main() {
    int array[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % SIZE;
    }

    puts("Before sorting");
    print_array(array, SIZE);

    puts("Ascending");
    bubblesort(array, SIZE, ascending);
    print_array(array, SIZE);

    puts("Descending");
    bubblesort(array, SIZE, descending);
    print_array(array, SIZE);
}
