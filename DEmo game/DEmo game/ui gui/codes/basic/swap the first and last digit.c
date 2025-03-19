// swap the first digit and last digit of a number
// first i need to count how many digit present in the number
# include <stdio.h>

int count (int n){
    int i;
    for(i=0;n!=0;i++){
        n=n/10;
    }
    return i;
}
int powr (int n,int m){
    int i,k=1;
    for (i=1;i<=m;i++){
        k=k*n;

    }
    return k;
}
int main()

{
    
     int n,firstd,lastd;
     scanf("%d",&n);
     int m,i,j,k,l,c;
     c=count(n)-1;
     lastd=n%10;
     firstd=n/powr(10,c);
    
     n=n%powr(10,c);
     n=n/10;
     n=lastd*powr(10,c)+n*10;
     n=n+firstd;
     printf("%d",n);
    

    
    
   
    
    
    
    
    }
