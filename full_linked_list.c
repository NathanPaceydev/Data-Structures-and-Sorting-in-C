#include <stdio.h>
#include <stdlib.h>

//linked list with push front and back
//and a pop front and back values

typedef struct Node{
    int value;
    struct Node* next;
} snode;

//printing function
void print_list( struct Node* n){
    while (n!=NULL){
        printf(" %d ", n->value);
        n=n->next;
    }//print_list;
}

void push_back(snode *head, int value){
    snode * current =head;
    
    while ( current ->next !=NULL){
        current = current ->next;
    }
    current->next = (snode *)malloc(sizeof(snode));
    current ->next-> value = value;
    current ->next->next = NULL;
}//push_back:

void push_front(snode ** head, int new_value){
    snode * new_node;
    new_node = (snode *)malloc(sizeof(snode));
    
    new_node->value = new_value;
    new_node->next = *head;
    *head = new_node;
}//push_front;

int pop(snode ** head){
    int return_value =-1;
    snode * next_node = NULL;
    
    if (*head == NULL){
        return -1;
    }
    
    next_node = (*head)->next;
    return_value = (*head)-> value;
    free(*head);
    *head = next_node;
    
    return return_value;
}//pop;

int remove_back(snode *head){
    int return_value = 0;
    
    
    snode *current = head;
    while (current ->next->next !=NULL){
        current =current->next;
    }
    
    return_value = current ->value;
    free(current->next);
    current->next=NULL;
    return return_value;
}


    int main( )
{
    //main implemetation of functions
    printf("\nProgram utilizes pop and push features in a linked list\n");
    struct Node * head =NULL;
  
    
    head = (struct Node*)malloc(sizeof(struct Node));
   


    if (head == NULL){
        return 1;
    }
    
    head -> value = 1;
    head -> next = NULL;
    
    //example use of the functions
    print_list(head);  printf("\n");
            
   push_back(head,3);
    print_list(head);   printf("\n");
    
  push_front(&head,3);
    print_list(head);   printf("\n");
    
    push_front(&head,5);
    print_list(head);   printf("\n");
    
    push_back(head,3);
    print_list(head);   printf("\n");
    
    pop(&head);
    print_list(head);   printf("\n");
    
    remove_back(head);
    print_list(head);   printf("\n");

    pop(&head);
    print_list(head);   printf("\n");
    
    remove_back(head);
    print_list(head);   printf("\n");
   
    
    return 0;
}

	
