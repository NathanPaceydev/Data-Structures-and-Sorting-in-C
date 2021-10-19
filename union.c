#include <stdio.h>
union unionExample{ 
    
    float i;
    double f;
    char array[5];
} uExample;

struct structExample{
    float i;
    double f;
    char array[5];
} sExample;

int main(){
    printf("Shows the Difference Between Structure and Union\n");
    printf("Size of structure: %d\n", sizeof(sExample));
    printf("Size of union %d \n", sizeof(uExample));
    
}
