// write a that remove first the first digit print the remaining digit 
# include <stdio.h>
# include <math.h>
int  count (int   n){
    int i;
    for(i=0;n!=0;i++){
        n=n/10;
    }
    return i-2;
}
int main()
{
    int  n,c,i,f,j,s=0;
    scanf("%d",&n);
    j=n;
    c=count(n);
    s=pow(10,c);

    for(i=0;i<=c;i++){
        f=j %10;
        j=j/10;
        s=s+(f*pow(10,i));
    
       
        
    }
    printf("%d",s-100);
    
}