/*
prints a table of values for sine and cosine between (0, 1)
March 23, 2022
*/

#include<stdio.h>
#include<math.h> //includes sin() and cos()

int main(void)
{ 
    int numberOfValues = 11;

    double interval;
    int i;
    printf("\n---SINE TABLE---\n"); //header for sine table
    for(i = 0; i < numberOfValues; i++)
    {
        interval = i/(numberOfValues - 1.0);
        printf("sin(%lf) = %lf \n", interval, sin(interval));
    }
    printf("\n---COSINE TABLE---\n"); //header for cosine table
    for(i = 0; i < numberOfValues; i++)
    {
        interval = i/(numberOfValues - 1.0);
        printf("cos(%lf) = %lf \n", interval, cos(interval));
    }
    printf("\n----END----\n");
    return 0;
}
