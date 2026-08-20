#include <stdio.h>

int main (int argc, char** argv)
{

int age;
printf("Enter your age: ");
scanf("%d", &age);

if (age>=13 && age<=19) 
    {printf ("Yyear you are a teenager!\n");}

else 
    {printf ("No you are still a kido\n");}

    return 0;

}

