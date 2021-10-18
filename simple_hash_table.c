 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

//data structure for a hash table
struct list{
    int key;
    int data;
} list;

struct list *array; // pointer to the array since it allocates less memory
int capacity = 10; //max capacity of the hash table array
int size =0;

int size_of_hashtable(){
    return size;
}

//Hash Function takes the key and return the index
int hashFunction(int key){
    //for simple hash, just use mod 
    int func= key%capacity;
    return func;
}//hashFunction;

// we are going to use a prime number capacity for the index of the array
//Checks if a number n is prime
int checkPrime(int n){
    int i;
    if(n==1 ||n==0){
        return 0;
    }
    for(i=2; i<n/2; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}//checkPrime;

//uses checkPrime to get the prime number 
int getPrime(int n){
    if(n%2==0){
        n++;
    }
    while (!checkPrime(n)){
        n+=2;
    }
    return n;
}//getPrime;

//now need to make the hash array using the prime capacity
void init_array(){
    capacity = getPrime(capacity);
    array = (struct list*)malloc(capacity* sizeof(struct list)); 
    
    for(int i =0; i<capacity; i++){
        array[i].key = 0;//initalize the array with all zero int
        array[i].data = 0;
    }
}//init_array;

//need a method of inserting a key data pair
void insert (int key, int data){
    //need to use the hashFunction to find the index of the array
    int index = hashFunction(key);
    
    //check if there is an existing value in the array 
    if(array[index].data==0){
        array[index].data = data;
        array[index].key = key;
        size ++;
        printf("\nThe Key %d has been inserted\n ", key);
    }
    //checking if the item is already there
    else if(array[index].key ==key){
        array[index].data = data;
        printf("\nItem already in table\n");
    }
    else{
        //collision occured
        printf("\nCollision Occured\n");
    }
}//insert;

//Delete Function
void delete_element(int key){
    //first need to find the location of the element then free
    int index = hashFunction(key);
    //check if the element exists
    if(array[index].data==0){
        printf("\nItem not in Table\n");
    }
    else{
        //set the index of the item back to 0
        array[index].data = 0;
        array[index].key = 0;
        size--;
        printf("\nKey %d has been removed",key);
    }
}//delete_element;

//finally need a good visual of the hash table
void display(){
    int i;
  for (i = 0; i < capacity; i++)
  {
    if (array[i].data == 0)
    {
      printf("\n array[%d]: / ", i);
    }
    else
    {
      printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
    }
  }
}//display;



//driver program
int main(){
    
    int choice, key, data, n;
  int c = 0;
  init_array();

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
      scanf("%d", &data);
      insert(key, data);

      break;

    case 2:

      printf("Enter the key to delete-:");
      scanf("%d", &key);
      delete_element(key);

      break;

    case 3:

      n = size_of_hashtable();
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
    
    
}
