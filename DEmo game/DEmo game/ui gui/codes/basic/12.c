// write a program to reverse a number

#include <stdio.h>
int main()
{
    int n,r=0,l;
    scanf("%d",&n);
    // rev the number
     while(n!=0){
         r=r*10+n%10;
        n=n/10;
        

    }
    printf( "the reverse number is %d",r);
}