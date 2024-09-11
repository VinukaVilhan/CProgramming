//find the power of a given number to the given number by recursion

#include <stdio.h>

int findPowerToItself(int, int);

int main()
{
    int number = 0, count, answer;
    printf("Enter the number: ");
    scanf("%d", &number);
    count = number;
    answer = findPowerToItself(number, count);
    printf("The result %d", answer);
    return 0;
}

int findPowerToItself(int number, int count)
{
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return number * findPowerToItself(number, count - 1);
    }
}