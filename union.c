#include <stdio.h>
//using unions to find the largest number in a set
union Number{ 
     int n;
     int m;
     int i;
     int array[5];
}number;

int main() {
 union Number number;
  int temp=0;
    printf("\nEnter a number: ");
    scanf("%d", &temp);
    number.n = temp;
   printf("Number: %d\n", number.n);

  printf("\nEnter a number: ");
    scanf("%d", &temp);
    number.m = temp;
    //notice how we assigned the number.m to temp but if the number is bigger
    //it will print for number.n
   printf("Number: %d\n", number.n);

//watch ill do it again
 printf("\nEnter a number: ");
    scanf("%d", &temp); 
    number.i = temp;
 printf("Number: %d\n", number.n); //prints the last inputted num

//seeing what happens to an array if we fill it
for (int i=0; i<5; i++){
    printf("Enter a number for the array[%d]: ", i+1);
    scanf("%d", &number.array[i]);
}
for(int i=0; i<5;i++){
     printf("Number: %d\n", number.array[i]); //prints the last inputted num

}

printf("Number: %d\n", number.n); //prints the last inputted num

}
