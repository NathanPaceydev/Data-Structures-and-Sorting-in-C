#include <stdio.h>
#include <stdlib.h>
//Program to use a Selection Sort
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//swap;

int selection_sort(int array[], int size){
    for(int j =0; j<size-1; j++){
        int min_value = j;
        for(int i=j+1; i<size; i++ ){
            //for ascending order
            if(array[j]>array[i]){
               min_value = i;
            }
        }
         swap(&array[min_value], &array[j]);
    }
}//selectio_sort;

void print(int array[], int size){
    for (int i =0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(int argc, char **argv)
{
    printf("Selection Sort Program\nArray:\n");
	int array[] = {2, 12, 7, 8, 1, 10, 11, 5, 6, 13};
    int size = sizeof(array)/sizeof(array[0]);
    print(array, size);
    
    selection_sort(array, size);
    printf("Sorted array\n");
    print(array, size);

}
