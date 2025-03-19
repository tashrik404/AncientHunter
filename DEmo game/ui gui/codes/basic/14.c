// calculate the sum of digit
# include <stdio.h>
int main()
{
    int i,n,sum=0,lastd;
    scanf("%d",&n);
    while(n!=0){
        lastd=n%10;
        n=n/10;
        sum=sum+lastd;

    }
    printf("the sum of digit is %d",sum);
}