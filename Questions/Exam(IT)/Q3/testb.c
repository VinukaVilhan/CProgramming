#include <stdio.h>

int getSum(int );

int main()
{
    int sum, number;
    printf("Enter a number: ");
    scanf("%d", &number);

    sum = getSum(number);

    printf("The sum is : %d ", sum);

    return 0;
}

int getSum(int number)
{
    if(number == 0)
    {
        return 0;
    }
    else
    {
        return number + getSum(number - 1);
    }
}