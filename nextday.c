/*
Week 2 HW: Option 1
Prints out date and following day for: feb 28, mar 14, oct 31, and dec 31
April 1, 2022
*/

#include<stdio.h>
#include<ctype.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{month m; int d;} date;
int max, i;

void printday(date* dt) // includes enum cases and max days per month
{
    switch(dt-> m)
    {
        case jan: printf("January %d", dt->d); max = 31; break;
        case feb: printf("February %d", dt->d); max = 28; break;
        case mar: printf("March %d", dt->d); max = 31; break;
        case apr: printf("April %d", dt->d); max = 30; break;
        case may: printf("May %d", dt->d); max = 31; break;
        case jun: printf("June %d", dt->d); max = 30; break;
        case jul: printf("July %d", dt->d); max = 31; break;
        case aug: printf("August %d", dt->d); max = 31; break;
        case sep: printf("September %d", dt->d); max = 30;break;
        case oct: printf("October %d", dt->d); max = 31; break;
        case nov: printf("November %d", dt->d); max = 30; break;
        case dec: printf("December %d", dt->d); max = 31; break;
        default: printf ("error");
    }
}

date* nextday(date* dt)
{
    if (dt->d==max) //if date is last day of the month
    {
        dt->d = (dt->d + 1)%max; //remainder for max days to go to 1
        dt->m = (dt->m + 1)%12; //remainder for months to go to next month
    }
    else 
        dt->d = dt->d + 1;
    return dt;
}

int main()
{
    date date1 = {jan, 1};
    date date2 = {feb, 28};
    date date3 = {mar, 14};
    date date4 = {oct, 31};
    date date5 = {dec, 31};
    date dates[] = {date1, date2, date3, date4, date5}; //array for different dates
    for (i=0; i<5; i++)
    {
        printf("Date: ");
        printday(&dates[i]);
        printf("\nNext day: ");
        nextday(&dates[i]);
        printday(&dates[i]);
        printf("\n\n");
    }
    return 0;
}
