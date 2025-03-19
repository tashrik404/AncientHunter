// printf numbers upto n in reverse order
# include <stdio.h>
int main()
{
    int i,n;
    printf("enter the number :");
    scanf("%d",&n);
    for(i=n;i>0;i--){
        printf("%d\t",i);
    }
}