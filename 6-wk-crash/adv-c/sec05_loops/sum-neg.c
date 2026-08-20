/* This program will print a sum of the numbers given from the keyboard as input by the user, using the while loop
the program terminates when the input is a negative number*/
#include <stdio.h>
int main()
{
int number, sum;
sum =0;
printf("Enter a positive number, negative number to terminate:  ");
scanf("%d", &number);

while (number>=0) {
  sum += number;
printf("Enter a positive number, negative number to terminate:  ");
scanf("%d", &number);

}
printf("Sum of the numbers = %d\n", sum);
}