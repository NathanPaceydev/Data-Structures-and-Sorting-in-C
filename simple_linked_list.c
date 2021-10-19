#include <stdio.h>
#include <stdlib.h>
//Simple linked list code 
//creates a linked list with 4 nodes

typedef struct Node{
    int value;
    struct Node* next;
} ;

void print_list( struct Node* n){
    while (n!=NULL){
        printf(" %d ", n->value);
        n=n->next;
    }
}

int main( )
{
    printf("\nProgram to create a Simple linked list with 4 linked nodes\n");
    struct Node * head =NULL;
    struct Node * second =NULL;
    struct Node * third =NULL;
    struct Node * fourth =NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));


    if (head == NULL){
        return 1;
    }
    
    head -> value = 23;
    head -> next = second;
    
    second -> value = 12;
    second->next = third;
    
    third -> value = 13;
    third-> next = fourth;
    
    fourth->value = 4;
    fourth->next = NULL;
    
    print_list(head);
    
    printf("\n");
    
    return 0;
}
