#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash(int key){
    return key%SIZE;
}//hash;

int prime(){
    int i = 0;
    for (i=SIZE; i>0; i--){
        for(int n =i; n>1; n--){
            if (n%i==0){
                return 0;
            }
        }
    }
    return i;
}

//quadractic probing func
int doubleH(int H[ ], int key){
    int index = prime()-(key%SIZE);
    int i=0;
    while(H[(index+i)%SIZE] !=0){
        i++;
    }
    return (index +i)%SIZE;
}//doubleH;

void insert(int H[ ], int key){
    int index = hash(key);
    
    if(H[index]!=0){
        index = doubleH(H,key);
    }
    H[index]=key;
}//insert

int search (int H[ ], int key){
    int index = hash(key);
    int i=0;
    while(H[(index+i)%SIZE !=key]){
        i++;
    }
    return (index+i)%SIZE;
}//search;

//simple printing func
void print(int H[]){
    int i=0;
    for(i=0;i<SIZE;i++){
    printf("index %d --%d\n",i, H[i]);
    }
}

int main(int argc, char **argv)
{

 int array[SIZE]= {0};

insert(array, 12);
insert(array, 25);
insert(array, 35);
insert(array, 26);


print(array);
 printf("\n");
 
 insert(array, 22);
 insert(array, 32);
  insert(array, 42);
 print(array);
 printf("\n");
return 0;  
    
}
