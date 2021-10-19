//https://www.youtube.com/watch?v=sFVxsglODoo&ab_channel=mycodeschool
//based on this code

#include <stdio.h>
#include <stdlib.h>
//program for learning stacks

//defining the global variables
// defining the size of the array to place stack
#define MAX_SIZE 101
//initalizing the array
int array[MAX_SIZE];
//setting top to -1 so the stack can start the first array input at top =0
//also good for checking for empty array
int top =-1;

void Push(int x){
    //check for overflow since we are adding var
    if(top== MAX_SIZE -1){
        printf("Error: Too many inputs\n");//error message stack overflow
        return;
    }
    //push adds one so top index gets bigger
    top++;
    //set the value of top to x
    array[top] =x;
}//Push

void Pop(){
    //check for empty array
    if(top==-1){
        printf("No Elements in stack");//error msg
        return;
    }
    top --;//decreasing since taking values out of the array
}//Pop

int Peek(){
    return array[top];
}//Peek

int isEmpty(){
    if (top==-1) return 1;
    return 0;
}

//function to print the stack
void Print() {
    printf("Stack: ");
    for(int i=0;i<=top;i++){
        printf("%d  ",array[i]);

    }
            printf("\n");
}

int main(){
    Push(2);     Print();
    Push(5);     Print();
    Push(10);   Print();
    Pop();  Print();
    Push(12); 
    Print();
    
}
