#include <stdio.h>
#include <stdlib.h>

int main ()

{
    char ch;
    int i, j;
    printf("Enter an integer:  ");
    scanf("%d", &i);
    
    printf("Enter an character:    ");
    scanf(" %c", &ch);
    printf("Enter a second integer: ");
    scanf("%d", &j);
    printf("What we have entererd are Character = %c, Integer 1 = %d, integer 2 = %d\n\n", ch, i, j);
    

    return 0;

}