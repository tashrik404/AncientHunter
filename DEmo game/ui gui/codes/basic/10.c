// find c program that find the first and last digit of a number 
#include <stdio.h>
int main()
{
    int n,i,k,m;
    printf("enter the number :");
    scanf("%d",&n);
    m=n;
    m=m%10;
    for(i=0;n>=10 ;i++){
        
        n=n/10;
    }
    printf("the first digit is %d and last digit is %d",n,m);
}