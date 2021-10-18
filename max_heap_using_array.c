#include <stdio.h>
#include <stdlib.h>
//Program for Max Heap using array

int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//swap;

void heapify(int array[ ], int size, int i){
    //check for NULL heap
    if (size==0){
        printf("No elements in heap\n");
    }
    if(size==1){
        printf("One element in heap\n");
    }
    else{
        //heapify for Max
        int largest = i;//variable to store parent
        int left = 2*i+1; //algorithm for left child
        int right = 2*i+2; //algorithm for right child
        
        if(left<size && array[left]>array[largest]){
            largest = left;
        }
        if(right<size && array[right]>array[largest]){
            largest = right;
        }
        if(largest != i){
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}//heapify;

void insert(int array[], int newNum){
    //check if heap is empty
    if (size==0){
        array[0] = newNum;
        size = size +1;
    }
    else{
        array[size] = newNum;
        size +=1;
        
        for(int i = size/2 -1; i>=0; i--){
            heapify(array, size, i);
        }
    }
}//insert;

void deleteRoot(int array[], int num){
int i;
    //finds the item   
 for( i =0; i<size; i++){
        if (num==array[i]){
            break;
        }
    }
    //delete while conserving the heap property
    swap(&array[i], &array[size-1]);
    size =size -1;
    for(int i=size/2 -1; i>=0; i--){
        heapify(array, size, i);
    }
}//deleteRoot;

void print(int array[], int size){
    for(int i =0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}//print;


int main(int argc, char **argv)
{
	int array[10];
    printf("Inserting 3, 4, 9, 5, 2\n");
    
    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);
    
    printf("Program For Max Heap\n");
    print(array, size);
    
    deleteRoot(array, 4);
    
    printf("After deleting 4\n");
    print(array, size);
 

}
