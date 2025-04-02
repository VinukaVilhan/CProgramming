#include <stdio.h>

int main(){

    int number[6];
    int *p;

    p  = number;

    printf("Enter the array values: \n");
    for (int x = 0; x < 6; x++)
    {
        scanf("%d", (p+x));
    }

    printf("The results are: ");
    for (int x = 0; x < 6; x++)
    {
        printf("%d ", *(p+x));
    }

    return 0;
}