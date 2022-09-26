/*
Fibonacci sequence based on inputted integer
March 25, 2022
*/

#include<stdio.h>

long fib(int n)
{
    long f1 = 1, f2 = 1, sum; 
    int i;
    for (i = 0; i < n; i++)
    {
        sum = f1 + f2;
        printf("\n%ld + %ld = %ld", f1, f2, sum);
        f1 = f2;
        f2 = sum;
    }
    return f1, f2;
}
int main(void)
{
    int n;
    printf("\nInput integer: ");
    scanf("%d", &n);
    fib(n);
    printf("\n\n");
    return 0;
}
