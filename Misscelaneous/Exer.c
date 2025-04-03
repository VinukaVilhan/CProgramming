#include <stdio.h>


int main(){
    printf("Enter marks for 5 students: \n");

    int arr[5], sum = 0;

    for (int x = 0; x < 5; x++)
    {
        printf("Enter mark: ");
        scanf("%d", &arr[x]);
    }


    printf("The marks are: \n");

    for (int x = 0; x < 5; x++)
    {
        printf("%d \n", arr[x]);
    }

    printf("The average mark is: \n");
    for (int x = 0; x < 5; x++)
    {
        sum += arr[x];
    }

    printf("%d \n", sum / 5 );


    return 0;
}