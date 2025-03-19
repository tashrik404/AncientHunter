// write a c program that count the number of digit in a c program 
// how i would count a digit . i can divide it by and store the vaule in a variable then if vaule of the variable got o i will return the value of i
# include <stdio.h>
int main()
{
    int n,i;
    printf("enter the number");
    scanf("%d",&n);
    for(i=0;n!=0;i++){
        n=n/10;
    }
    printf("the digit of the numbe is %d",i);
}