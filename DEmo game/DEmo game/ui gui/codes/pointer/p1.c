# include <stdio.h>
int main()
{
    int x=1,y=2,z[10];
    printf("the initia value of x is %d\n",x);
    printf("the initial value of y is %d\n",y);
    int *ip;
    ip =&x;
    printf("the point to value is %d\n",*ip);
    y =*ip;
    printf("the new value of y is %d\n",y);
    *ip=0;
    printf("%d\n",*ip);
}