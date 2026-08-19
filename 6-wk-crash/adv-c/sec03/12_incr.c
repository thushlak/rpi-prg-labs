#include <stdio.h>

int main(){

int x = 12;

x = printf("%d", x++);

printf("%d", ++x);

return 0;

}