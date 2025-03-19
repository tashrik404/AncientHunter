# include <stdio.h>
# include <string.h>
struct book{
    char name[50];
    int price;
    int pages;
}a,b,c;
int main()
{
  printf("enter the first book attributes :");
  gets(a.name);
  scanf("%d",&a.price);
  scanf("%d",&a.pages);
  puts(a.name);
  printf("%d\n",a.price);
  printf("%d\n",a.pages);


}