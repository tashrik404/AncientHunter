// write a program to check if it is palindrome or not
# include <stdio.h>
int rev(int n){
    int i,k=0;
    while(n!=0){
        k=k*10+n%10;
        n=n/10;
    }
    return k;
}
int main ()
{
    int n;
    scanf("%d",&n);
    int m=rev(n);
    if(n==m){
        printf("the number is palindrome ");
    }
    else{
        printf("the number is not palindrome");
    }
}
