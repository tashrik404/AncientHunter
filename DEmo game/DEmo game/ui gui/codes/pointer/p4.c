# include <stdio.h>
// find the output 
//
int main ()
{
    int x=5;
    int *p=&x;
    *p=6;
    int **q=&p;
    int ***r=&q;
    printf("%d\n",*p);
    printf("%d\n",*q);
    printf("%d\n",**q);
    printf("%d\n",**r);
    printf("%d\n",***r);
}