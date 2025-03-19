# include <stdio.h>
typedef struct record{
    char name[50];
    int age;
    int match;
    float avg;


} cric;
int main()
{
    cric arr[3];
    int i;
    for(i=0;i<3;i++){
        gets(arr[i].name);
        scanf("%d",&arr[i].age);
        scanf("%d",&arr[i].match);
        scanf("%f",&arr[i].avg);
    }
    for(i=0;i<3;i++){
        puts(arr[i].name);
        printf("%d\n",&arr[i].age);
        printf("%d\n",&arr[i].match);
        printf("%f\n",&arr[i].avg);
    }

}