// write a c program to print a  multiplication of n upto 10
# include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=10;i++){
        printf(" %d x %d = %d\n",n,i,n*i);
    }
}