#include <stdio.h>
#include <stdlib.h>

int main ()

{
  int a, b, c;
  float average;
  printf ("1st_number    :");
  scanf ("%d", &a);

  printf ("2nd_number    :");
  scanf ("%d", &b);

  printf ("3rd_number    :");
  scanf ("%d", &c);

  average = (((float)a+b+c)/3);

  printf ("Tne Average of all three are %f\n", average);

  return 0;

}

