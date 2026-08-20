#include <stdio.h>
int main ()

{
  int n, sum , i;
  printf ("Enter n: ");
  scanf("%d", &n);

  sum =0;
  i  = 0;

  while (i <= n )

  {
  sum += i ++; //NOTE this must be += not + = 
  //sum = sum + i ++; this is again re-written using another smart operator 
  // i++;   //  we will get rid of this by adding  + i++ as a unary operator 
  }
  
  printf("Sum of first  %d natural numbers = %d\n", n , sum);
  return 0;

}
