#include <stdio.h>

int main()
{
    //header rows
    printf("x ");
    for (int x = 1; x <= 12; x++)
    {
        printf("%d ", x);
    }

    printf("\n");
    // the table rows
    for(int x = 1; x <= 12; x++)
    {
        printf("%d ", x);
        for(int y = 1; y <= 12; y++)
        {
            printf("%d ", x*y);
        }
        printf("\n");
    }
    return 0;
}