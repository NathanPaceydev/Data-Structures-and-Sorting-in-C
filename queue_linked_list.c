/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
//Node implementation
struct Node{
    //value
    int data;
    //pointer to the next node
    struct Node * next;
} ;

//make front and rear global var and set to NULL
struct Node* front =NULL;
struct Node* rear = NULL;

//Enqueue using the node and an int
int Enqueue(int x){
    //assign a temp var to Node and assign enough space
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //assign the value of temp to x
    temp->data = x;
    //pointer to the item after next is NULL
    temp->next = NULL;
    //check if queue is empty
    if(front==NULL && rear == NULL){
        //set both front and rear to new node
        front = rear = temp;
        return;
    }
   //general enqueue 
   //set the rears pointer to the next node to temp
   rear->next = temp;
   // set rear to new node
   rear = temp;
    
}//Enqueue;

void Dequeue(){
    //temp pointer to Node of front
    struct Node* temp = front;
    //check for empty queue
    if(front == NULL){
        printf("Queue is Empty!!\n");
        return;
    }
    //check if front = rear
    if(front == rear){
        front = rear =NULL;
    }
    //general operation
    else{
        //set the front to the one behind it in queue
        front = front -> next;
    }
    //delete the temp, print the item dequeued
    printf("Served %d\n", temp->data);
    free(temp);
}//Dequeue;

//print function
void Print(){
    
    struct Node* temp = front;
    while (temp != NULL){
        printf("%d  ", temp->data);
        temp = temp -> next;
    }
printf("\n");
}

//driver  function to test code
int main(){

	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();

return 0;
}
