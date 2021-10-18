#include <stdio.h>
#include <stdlib.h>
//Program to use a Insertion Sort
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//swap;

void insertionSort(int array[], int size) {
    for (int i =1; i<size; i++){
    int key = array[i];//setting a temp var to swap with
        //for descending change array[i-1]>key to array[i-1]<key
        while(array[i-1]>key && (i-1)>=0){
        swap(&array[i-1], &array[i]);
        i--;
        }
    }
}//insertionSort;

void print(int array[], int size){
    for (int i =0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(int argc, char **argv)
{
    printf("Insertion Sort Program\nArray:\n");
	int array[] = {2, 12, 7, 8, 1, 10, 11, 5, 6, 13};
    int size = sizeof(array)/sizeof(array[0]);
    print(array, size);
    
    insertionSort(array, size);
    printf("Sorted array\n");
    print(array, size);

}
