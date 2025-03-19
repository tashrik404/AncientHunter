

# include <stdio.h>
int main()
{
    char c;
    for( ; ;){
    scanf (" %c",&c);
    if(c>='a' && c<='z'){
        break;
    }
    else{
        printf("invalid input  please enter again\n ");

    }
    }


    int n,i;
    n=c;
    for (i=97;i<=n;i++){
        printf("%c\t",i);
    }
    

        
    
}
