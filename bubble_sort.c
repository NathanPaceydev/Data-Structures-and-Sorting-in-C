#include <stdio.h>
#include <stdlib.h>
//Simple Bubble Sorting program

int bubble_sort(int array[], int size){
    for(int j =0; j<size-1; j++){
        for(int i=0; i<size-j-1; i++){
            //for ascending order change '<' to '>'
            if(array[i]<array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}//bubble_sort;

//printing the array to check
void print(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    printf("\tProgram that sorts using a bubble sorting algorithm\n");
    
    int array[ ] = {1, 3, 4, 11, 12, 8, 9, 10, 6, 7};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Inital Array:\n");
    print(array, size);
    bubble_sort(array, size);
    printf("Sorted Array:\n");
	print(array, size);
	return 0;
}
