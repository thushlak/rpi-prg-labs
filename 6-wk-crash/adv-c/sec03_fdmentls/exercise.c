#include <stdio.h>
#include <stdlib.h>

int main()

{
  double rate;
  rate = 5.3;
  double principal_amount;
  double total_interest;
  int duration;

  printf ("Enter the duration in years:  ");
  scanf ("%d", &duration);
  printf ("Enter the amount of the loan: ");
  scanf ("%lf", &principal_amount);
  total_interest = principal_amount * rate * duration;
  printf ("The total interest payble: %f\n", total_interest);

  return 0;

}