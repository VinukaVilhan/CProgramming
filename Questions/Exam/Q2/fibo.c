#include <stdio.h>

void fibo(int);

int main()
{
    int num, prev = 0, next = 1;
    printf("Enter the nth term: ");
    scanf("%d", &num);

    fibo(num);
    
    return 0;
}

void fibo(int num)
{
    int prev = 0, next = 1, temp;
    printf("%d ", prev);

    if(num > 1)
    {
        printf("%d ", next);
    }

    for(int x = 1; x <num; x++)
    {
        temp = prev + next;
        printf("%d ", temp);
        prev = next;
        next = temp;
    }
}