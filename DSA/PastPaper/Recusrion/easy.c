#include <stdio.h>
#include <stdlib.h>

int factorial(int number)
{
    if(number == 0 || number == 1)
    {
        return 1;
    }
    else{
        return number * factorial(number -1);
    }
}

int main()
{
    printf("Factorial\n");
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("Result: %d", result);
    return 0;
}