# include <stdio.h>
int sumofelements(int A[],int size)
{ int i,sum=0;
    for(i=0;i<size;i++){
        sum=sum+A[i];
    }
    return sum;

}
int main()
{
    int A[]={1,2,3,4,5};
    
    int size = sizeof(A)/4;
    int total = sumofelements(A,size);
    printf("%d\n",total);

}