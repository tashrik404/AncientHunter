// write a basic program for struct
// create a sturucture type book with name,price and number of pages as its attributes
# include <stdio.h>
# include <string.h>
struct book{
        char name[50];
        float price;
        int page;
    }a,b,c;
int main()
{
    strcpy(a.name,"harry potter");
    a.price=750;
    a.page=350;
    printf("%f,%d,%s\n",a.price,a.page,a.name);
    strcpy(b.name,"alchemist");
    b.price=450;
    b.page=160;
    printf("%s,%f,%d\n",b.name,b.price,b.page);
    
}