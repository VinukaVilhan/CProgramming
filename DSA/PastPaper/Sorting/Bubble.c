#include <stdio.h>
#include <stdlib.h>

#define num 8

void display(int numbers[])
{
    for(int x = 0; x < num; x++)
    {
        printf("%d ",numbers[x]);
    }
    printf("\n");
}

int sort(int numbers[])
{
    for(int x = 0; x < num; x++)
    {
        for(int y = 0; y < num -x - 1; y++)
        {
            // if needed swap
            if(numbers[y] > numbers[y + 1] )
            {
                int temp = numbers[y];
                numbers[y] = numbers[y + 1];
                numbers[y + 1] = temp;
            }

        }
    }
}

int main()
{
    int numbers[] ={1,7,8,9,2,3,4,5};

    printf("Array before sorting: \n");
    display(numbers);

    sort(numbers);

    printf("Array after sorting: \n");
    display(numbers);
    return 0;
}