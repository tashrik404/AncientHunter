# include <stdio.h>
int main()
{
    int a;
    int *p;
    p=&a;
     a=5;
    printf("%d\n",*p);
    printf("%d\n",p);
    (*p)++;
    printf("%d nothing\n",*p);
    p++;
    *p=7;
  
    printf("%d\n",p);
    printf("%d\n",*p);

}