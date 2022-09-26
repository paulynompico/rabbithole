/*
Compute the average weight of elephant seals from
elephant_seal_data.txt
March 30, 2022
*/

#include<stdio.h>

int main(void)
{
    double sum = 0.0;
    int n = 0, i = 0;
    int weight[1000];

    FILE * f = fopen("elephant_seal_data.txt", "r"); //open the .txt file to import data
    while(fscanf(f, "%d,", &n) > 0)
    {
        weight[i++] = n; //assigning data to array
    }
    fclose(f);

    printf("\nThe weights are:\n");
    for(i=0; i < 1000; i++)
        printf("%d\t", weight[i]); //print the array to make sure the input was correct
    printf("\n\n");
    for(i=0; i < 1000; i++)
        sum = sum + weight[i];
    printf("The average weight of elephant seals is %.2f\n\n", sum/1000);
    return 0;
}
