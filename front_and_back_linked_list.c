#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} snode;

//printing function
void print_list( struct Node* n){
    while (n!=NULL){
        printf(" %d ", n->value);
        n=n->next;
    }
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


    int main( )
{
    printf("\nProgram to create an interactive linked list\n");
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
        
    int i = 1;
    while( i !=0){
        int j = 0;
        printf("Type 1 if you want to push a number on the back of the list: ");
        scanf("%d",&j);
        
        int num =0;
        if(j==1){
        printf("Type a number to add: ");
        scanf("%d",&num);
        
        push_back(&head,num);
        
        print_list(head);
        printf("\n");
        }
        printf("Type 2 if you want to push an item to the front of the list: ");
        scanf("%d",&j);
        
        if (j==2){
          printf("Type a number to add: ");
        scanf("%d",&num);
        
        push_front(&head,num);
        
        print_list(head);
        printf("\n");
        }
        
        printf("Type 0 to exit: ");
        scanf("%d",&i);
        
        }
        

   
    
    return 0;
}

	
