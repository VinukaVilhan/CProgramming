#include <stdio.h>

int main(){

    // declare 3*3 2D arr
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // declare pointer variable
    int *p;

    p = &arr[0][0];

    printf("The base address of the array: %p\n", p);

    printf("Elements of the array using pointer:\n");
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y< 3; y++)
        {
            printf("%d ", *(p + (x * 3) + y));
        }
        printf("\n");
    }

    return 0;
}