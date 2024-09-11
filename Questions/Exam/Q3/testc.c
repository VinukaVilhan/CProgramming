#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//dynamic array
long* arr;

int main()
{
    int count = 0;
    long input;
    arr = (long *)malloc( (count + 1) * sizeof(long));

    while(true)
    {
        printf("Enter the NIC number or type 0 to print the NIC of visitors according to the visiting order: ");
        scanf("%ld", &input);
        getchar();

        if(input == 0)
        {
            for(int x = count - 1; x >= 0 ; x--)
            {
                printf("%ld ", arr[x]);
            }
            break;

        }
        arr[count] = input;
        count++;
        printf("%d \n", count);
        arr = (long *)realloc(arr, (count + 1)  * sizeof(long));
        if(arr == NULL)
        {
            printf("Memory allocation has failed");
            return 1;
        }
    }
    free(arr);
    return 0;
}