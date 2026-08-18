#include <stdio.h>
#include <stdlib.h>

int main()
{
 
    char CH = 'A';
    printf ("Chracter name is: %c\n", CH);

    char another;
    printf ("Enter a character of your choice:  ");
    scanf ("%c", &another);
    printf ("The value of another chracter is %c\n", another);
    return 0;

}