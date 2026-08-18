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


    getchar();   // consume the '\n' left by scanf()

    printf ("Enter another character using getchar:  ");
    char new_char;
    new_char = getchar();
    printf("new char is %c\n", new_char );


        return 0;

}

