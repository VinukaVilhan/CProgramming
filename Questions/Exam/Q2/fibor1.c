// print the values until nth term
//print the nth term

#include <stdio.h>

int fibo(int );

int main()
{
    int num;
    printf("Enter the nth term: ");
    scanf("%d", &num);

    fibo(num);
    return 0;
}

int fibo(int num)
{
    if (num == 0)
    {
        printf("%d ", num);
    }
    else if (num == 1)
    {
        printf("%d ", num);
    }

    printf("%d", (fibo(num - 1) + fibo(num - 2)));
}