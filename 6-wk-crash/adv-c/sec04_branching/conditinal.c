#include <stdio.h>

int main()
{
int a,b,c,d,e,f,m,n;

    //First lets use the if else to evaulate a, b, c and m

    printf (" enter values for a, b, c  :");
    scanf ("%d %d %d", &a, &b, &c);
    printf ("a = %d, b = %d,c = %d\n",a, b, c);
    
    if (a>b && b>c)
        m = a;

    else if ( b > c)
        m = b;
    else
        m =c;
    printf("m = %d\n ", m);
    


//Conditional for the same thing#

 printf("now ebeter the values for d,e,f  :");
 
 scanf("%d %d %d", &d, &e, &f);
 printf("d =%d, e=%d, f=%d\n", d,e,f);
 n = d>e && e>f ? d :
     e>f ? e : f;
 printf("n = %d\n", n);
 return 0;

}

