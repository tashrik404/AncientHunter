//printf all odd numer in given range 
#include <stdio.h>
int main()
{
    int n,m,i;
    printf("enter the first number");
    scanf("%d",&n);
    printf("enter the last number ");
    scanf("%d",&m);
    for(i=n;i<=m;i++){
        if(i%2!=0){
         printf("%d\t",i);
        }
    }
        
}