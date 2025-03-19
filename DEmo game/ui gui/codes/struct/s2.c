// create a structure type person with name salary and age as its attributes
//declare and initialize 2 variables for this print the name of first person and 
//age of ohter
# include <stdio.h>
# include <string.h>
struct person{
    char name[50];
    int salary;
    int age;

}a,b;
int main()
{
    strcpy(a.name,"tashrik");
    a.age=22;
    b.age=36;
    printf("%s,%d,%d",a.name,a.age,b.age);


}