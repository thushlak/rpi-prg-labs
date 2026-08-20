#include <stdio.h>

int main()

{

int x = -1, y = -2;

if (++x<++y)

if(x<y)

printf("Hello, ");

else

printf("Hi, ");

else

printf("Hey, ");

printf("x = %d y = %d\n", x, y);

return 0;

}