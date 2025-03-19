// sum of all natarul number upto n
# include<stdio.h>
int main()
{
    int i,n,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        s=s+i;

    }
    printf("the sum is %d",s);
}