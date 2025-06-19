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
    for(int x = 1; x < num; x++)
    {
        int select = numbers[x];

        int y = x - 1;

        while(y >= 0 && numbers[y] > select)
        {
            numbers[y + 1] = numbers[y];
            y--;
        }

        numbers[y + 1]=select;
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