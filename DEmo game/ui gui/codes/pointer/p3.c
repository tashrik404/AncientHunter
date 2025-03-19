// swap two variable by using pointer and function 
# include <stdio.h>
int swap (int *p ,int *p1){
    int temp;
    temp=*p;
    *p=*p1;
    *p1=temp;


}
int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    swap(&a,&b);
    printf("%d\n %d\n",a,b);
}