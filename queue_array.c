#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAX 5
//Queue implementation in C
//Nathan Pacey
int items[SIZE_MAX], front =-1, rear =-1;

void enQueue(int value) {
    //checks if queue is full
    if (rear == SIZE_MAX -1){
        printf("\nQueue is Full!\n");
    }
    else{
        //sets the first element "front" to value 0
        if(front ==-1){
            front = 0;
        }
        //increases the rear by 1
        rear ++;
        //add new element to the "rear:
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}//enQueue;


void deQueue() {
    //check if Queue is empty
    if (rear == -1){
        printf("The Queue is Empty!! \n");
    }
    else{
        //return value;
        printf("\nDeleted -> %d\n", items[front]);
        //increase front by one
        front ++;
        //last element condition
        if(front > rear){
            //if last element reset the values for front and rear to -1
        front = rear = -1;
        }
        //you can add a call to print to print the Queue
        print();
    }
}//deQueue;


void print(){
   if (rear == -1)
    printf("\nQueue is Empty!!!\n");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n"); 
}//print;


//driver function
int main(int argc, char **argv)
{
	//you can add calls to any of the functions here to complete a queue

    //enQueue 5 elements
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
    
    print();
//can't add a 6th size Size MAX is 5
enQueue(6);
//removes and prints the new queue
deQueue();
deQueue();


	return 0;
}
