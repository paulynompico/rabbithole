/*
Reads integers from file "num-hw3", with first number as size of array
Computes the average and finds the highest number
Prints both in terminal and in output file "answer-hw3"
April 15, 2022
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_NUM 99

void read_data(FILE *ptr, int d[], int *size) //read all numbers in file
{
    *size = 0;
    while(fscanf(ptr, "%d", &d[*size]) == 1)
        (*size)++;
}

void print_highest(FILE *ptr, int d[], int size) //find and print highest number (to output file)
{
    int i;
    for( int i = 2; i <= size; i++){
        if (d[1] < d[i]){
            d[1] = d[i];
        }
    }
    fprintf(ptr, "\nThe highest number is: %d", d[1]);
    fprintf(ptr, "\n\n");
}

void print_data(FILE *ptr, int d[], int size) //print numbers excluding data[0], which is assigned as sz (to output file)
{
    int i;
    fprintf(ptr, "\nThe numbers in the array are: \n");
    for(i = 1; i <= size; i++)
    {
        fprintf(ptr, "%d\t", d[i]);
        if ((i+1) % 10 == 0) printf("\n");
    }
}

void print_average(FILE *ptr, int d[], int size) // print average (to output file)
{
    int i;
    double avg = 0.0;
    for(i = 1; i <= size; i++)
        avg += d[i];
    fprintf(ptr, "\n\nThe average of the %d numbers is: %10f", size, avg/size);
}

void print_file(FILE *fptr) //print results in terminal
{
    int c;
    rewind(fptr);
    while((c = getc(fptr)) != EOF)
        putc(c, stdout);
}

int main()
{
    int i, sz;
    FILE *ifp, *ofp;
    int data[MAX_NUM] = {0};

    ifp = fopen("num-hw3", "r+");
    ofp = fopen("answer-hw3", "w+");
    read_data(ifp, data, &sz);
    sz = data[0]; //assign data[0] as size

    print_data(ofp, data, sz);
    print_average(ofp, data, sz);
    print_highest(ofp, data, sz);
    print_file(ofp);

    fclose(ifp);
    fclose(ofp);
    return 0;
}
