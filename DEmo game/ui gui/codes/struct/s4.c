#include <stdio.h>
typedef struct date  {
    int date;
    int month;
    int year;

 
}date;
int main()
{   date arr[2];
    int i;


    for(i=0;i<2;i++){
        scanf("%d",&arr[i].date);
        scanf("%d",&arr[i].month);
        scanf("%d",&arr[i].year);

    }
    arr[0]=arr[1];
    for(i=0;i<2;i++){
        printf("date :%d\n",arr[i].date);
        printf("month :%d\n",arr[i].month);
        printf("year:%d\n",arr[i].year);
    }

    return 0;
}