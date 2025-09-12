#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 30
#define INPUT_SIZE 80

void bubblesort(int a[], int n, int (*ascending_or_descendig)(int elem1, int elem2));
void swap(int *x, int *y);
void print_array(int a[], int n, int highlight1, int highlight2);
int ascending(int elem1, int elem2);
int descending(int elem1, int elem2);

int main(){
    int array[SIZE];

    srand(time(NULL));
    for(int i=0; i<SIZE; i++){
        array[i] = rand() % 1000;
    }
    puts("Before sorting:");
    print_array(array, SIZE, -1, -1);

    char answer[INPUT_SIZE];
    puts("1 for ascending, 2 for descending");
    fgets(answer, INPUT_SIZE, stdin);
    answer[strcspn(answer, "\n")] = '\0';

    if(strcmp(answer, "1") == 0){
        puts("Ascending order:");
        bubblesort(array, SIZE, ascending);
    }
    else if(strcmp(answer, "2") == 0){
        puts("Descending order:");
        bubblesort(array, SIZE, descending);
    }
    else{
        puts("No valid answer");
    }

    //print_array(array, SIZE);
}

void bubblesort(int a[], int n, int (*ascending_or_descendig)(int elem1, int elem2)){
    for(int pass=1; pass<n; pass++){
        int swapped = 0;
        for(int count=0; count<n-1; count++){
            if((*ascending_or_descendig)(a[count], a[count+1])){
                swap(&a[count], &a[count+1]);
                swapped = 1;

                //clear screen
                printf("\033[2J\033[H");
                print_array(a, n, pass, pass+1);
                usleep(80000);
            }
        }
        if(swapped == 0){
            break;
        }
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int a[], int n, int highlight1, int highlight2){
    for(int i=0; i<n; i++){
        if(i == highlight1 || i == highlight2){
            printf("\33[31m%4d\033[0m", a[i]);  //Red for swapped elements
        }
        else{
            printf("%4d", a[i]);
        }
        if((i+1) % 10 == 0){
            putchar('\n');
        }
    }
    putchar('\n');
    fflush(stdout);
}

int ascending(int elem1, int elem2){
    return elem1 > elem2;
}

int descending(int elem1, int elem2){
    return elem1 < elem2;
}
