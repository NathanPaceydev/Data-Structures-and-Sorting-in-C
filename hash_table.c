#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//start with the basic struct
typedef struct List{
    char *key;
    char *value;
    struct List* next;
} List;

//need to define the array of the hash table
typedef struct HashTable{
   unsigned int size;
    List** array;
} HashTable;



//create the hash table
HashTable* ht_create(unsigned int size){
    HashTable *ht;
    
    if(size<1){
        return NULL;
    }
    ht=malloc(sizeof(HashTable));
    if(ht==NULL){
        return(NULL);
    }
    
    memset(ht->array, 0, size* sizeof(List));
    ht->size = size;
    
    return ht;
}//ht_create;

//hash function
unsigned int hash(const char *key, unsigned int size){
    unsigned int hash;
    unsigned int i;
    
    hash = 0;
    i = 0;
    while(key&&key[i]){
        hash=(hash +key[i])%size;
        i++;
    }
    return(hash);
}//hash;

//need to allocate space and handle if the node key doesnt exist
int ht_put(HashTable* hashtable, const char* key, const char* value){
    List* node;
    
    if(hashtable==NULL){
        return 1;
    }
    node=malloc(sizeof(List));
    if(node==NULL){
        return 1;
    }
    node->key = strdup(key);
    node->value = strdup(value);
    
    node_handler(hashtable, node);
    return 0;
}//ht_put;

void node_handler(HashTable* hashtable, List* node){
    unsigned int i = hash(node->key, hashtable->size);
    List* tmp = hashtable->array[i];
    
    if(hashtable->array[i] != NULL){
        tmp = hashtable->array[i];
        while(tmp !=NULL){
            if(strcmp(tmp->key, node->key)==0){
                break;
            }
            tmp = tmp->next;
        }
        if(tmp==NULL){
            node->next = hashtable->array[i];
            hashtable->array[i] = node;
        }
        else{
            free(tmp->value);
            tmp->value = strdup(node->value);
            free(node->value);
            free(node->key);
            free(node);
        }
        }else{
        node->next = NULL;
        hashtable->array[i];
        }
    }//node_handler
    
    //now must be able to traverse the list (hash array)
    char *ht_get(HashTable* hashtable, const char *key){
        
        char *key_cp;
        unsigned int i;
        List* tmp;
        
        if(hashtable==NULL){
            return NULL;
        }
        key_cp = strdup(key);
        i= hash(key, hashtable->size);
        tmp = hashtable->array[i];
        
        while(tmp !=NULL){
            if(strcmp(tmp->key, key_cp)==0){
                break;
            }
            tmp = tmp->next;
        }
        free(key_cp);
        
        if(tmp==NULL){
            return NULL;
        }
        return tmp->value;
    }//ht_get;
    
    //now implement the delete func
    void ht_free(HashTable* hashtable){
        List* tmp;
        unsigned int i;
        
        if (hashtable ==NULL){
            return NULL;
        }
        
        for(i=0; i<hashtable->size; i++){
            if(hashtable->array[i] !=NULL){
                //traverse and free the node
                while(hashtable->array[i] != NULL){
                    tmp = hashtable->array[i]->next;
                    free(hashtable->array[i]->key);
                     free(hashtable->array[i]->value);
                      free(hashtable->array[i]);
                      hashtable->array[i] = tmp;
                }
                free(hashtable->array[i]);
            }
        }
        free(hashtable->array[i]);
        free(hashtable);
    }//ht_free;
    
    void display(HashTable* hashtable){
         List* tmp;
    int i;
  for (i = 0; i < hashtable->size; i++)
  {
    if (hashtable->array[i]->value == 0)
    {
      printf("\n array[%d]: / ", i);
    }
    else
    {
      printf("\n key: %d array[%d]: %d \t", hashtable->array[i]->key, i, hashtable->array[i]->value);
    }
  }
}//display;
    
    
    //*********************
int main(void)
{

    HashTable* ht;
    
    ht = ht_create(1);
    
    int choice, key, value, n;
     unsigned int size;
  int c = 0;
  
    do
  {
    printf("1.Insert item in the Hash Table"
         "\n2.Remove item from the Hash Table"
         "\n3.Check the size of Hash Table"
         "\n4.Display a Hash Table"
         "\n\n Please enter your choice: ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

      printf("Enter key -:\t");
      scanf("%d", &key);
      printf("Enter data -:\t");
      scanf("%d", &value);
      ht_get(key, value);

      break;

    case 2:

      printf("Enter the key to delete-:");
      scanf("%d", &key);
      ht_free(key);

      break;

    case 3:
  
      n = ht_create(size);
      printf("Size of Hash Table is-:%d\n", n);

      break;

    case 4:

      display();

      break;

    default:

      printf("Invalid Input\n");
    }

    printf("\nDo you want to continue (press 1 for yes): ");
    scanf("%d", &c);

  } while (c == 1); 
    
return 0;
}
