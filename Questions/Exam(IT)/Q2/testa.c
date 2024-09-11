#include <stdio.h>

int main()
{
    int deposit = 10000, total = 0, years = 0;

    while (total < 8000)
    {
        total += deposit* 0.2;
        years++;
    }

    printf("The years Lilly should wait is : %d", years);

    return 0;
}