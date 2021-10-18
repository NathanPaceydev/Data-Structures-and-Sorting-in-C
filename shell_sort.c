#include <stdio.h>
#include <stdlib.h>
//Simple Shell Sort program in C

void shell_sort(int array[], int size){
    //sorting algorithm
    for(int interval = size/2; interval>0; interval/=2){
        for(int i = interval; i< size; i++){
            int temp = array[i];
            int j;
            for (j = i; j>= interval && array[j-interval] > temp; j -= interval){
                array[j] = array[j-interval];
            }
            array[j]=temp;
        }
    }
}//shell_sort;

//printing the array to check
void print(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}//print;

//driver
int main(int argc, char **argv)
{
    printf("\tProgram that sorts using a Shell sorting algorithm\n");
    
    int array[ ] = {1, 3, 4, 11, 12, 8, 9, 10, 6, 7};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Inital Array:\n");
    print(array, size);
    shell_sort(array, size);
    printf("Sorted Array:\n");
	print(array, size);
	return 0;
}
