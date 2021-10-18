#include <stdio.h>
#include <stdlib.h>
//Program to use a Quick Sort in C
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//swap;

int partition(int array[], int low, int high){
    //set the pivot element to the last index
    int pivot = array[high];
    int i = (low-1);
    //put smaller elements to the left and greater elements to the right
    for (int j = low; j<high; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);//swap if smaller
        }
    }
    swap(&array[i+1], &array[high]);//place pivot next to the last lower element
    return (i+1);//returns the index of the pivot
}//partition;

void quicksort(int array[], int low, int high){
    if(low<high){
        //call partition and set equal to new int
        int par = partition(array, low, high);
        //sort lower array
        quicksort(array, low, par-1);
        //sort higher
        quicksort(array, par, high);
    }
}//quicksort;

void print(int array[], int size){
    for (int i =0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

//driver code
int main(int argc, char **argv)
{
    printf("Quick Sort Program\nArray:\n");
	int array[] = {2, 12, 7, 8, 1, 10, 11, 5, 6, 13};
    int size = sizeof(array)/sizeof(array[0]);
    int lower = 0;
    print(array, size);
    
    quicksort(array, lower, size-1);
    printf("Sorted array\n");
    print(array, size);

}
