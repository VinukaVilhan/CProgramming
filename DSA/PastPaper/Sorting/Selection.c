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


    // find the smallest and swap
    for(int x = 0; x < num; x++)
    {
        // smallest number index
        int smallest = x;
        
        for(int y = x +1 ; y < num ; y++)
        {
            if(numbers[y] < numbers[smallest])
            {
                smallest = y;
            }
        }

        // swap
        if(smallest != x)
        {
            int temp = numbers[x];
            numbers[x] = numbers[smallest];
            numbers[smallest] = temp;
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