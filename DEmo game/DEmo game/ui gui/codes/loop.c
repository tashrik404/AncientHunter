# include <stdio.h>
int main()
{
    int n,i,r,new=1;
    printf("enter the number:");
    scanf("%d",&n);


    for(i=0;n>=0;i++){
        r=n%10;
        n=n/10;
        new = r+(new*i);


    }

    printf("%d",new);
}