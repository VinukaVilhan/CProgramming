#include <stdio.h>

#define MAX_SIZE 50

// declare array
int numbers[MAX_SIZE];


void printFunc(int size){
    printf("Updated array: ");
    printf("Output: ");
    for(int x = 0; x < size; x++)
    {
        printf("%d ", numbers[x]);
    }
    printf("\n");
}

int main()
{
    int size, pos = 2, number;

    printf("Enter the actual size: ");
    scanf("%d", &size);

    if(size > MAX_SIZE || size < 1)
    {
        printf("Invalid size");
        return 1;
    }

    printf("Enter inputs: \n");
    for(int x = 0;  x < size; x++)
    {
        scanf("%d", &numbers[x]);
    }

    if(size >= MAX_SIZE){
        printf("Insertion is not possible!!");
        return 1;
    }

    printf("Enter the new input number for the 3rd position: ");
    scanf("%d", &number);

    //  shift elemts to the right
    for( int x = size; x > pos; x--){
        numbers[x] = numbers[x-1];
    }

    // insert new number 
    numbers[pos] = number;

    // increase array size
    size++;

    printFunc(size);
// -------------------------------------------------------------------------------------------------------------------------


    // insert element at the begining


    printf("Enter the element you want to enter: ");
    scanf("%d", &number);

    
    //  shift elemts to the right
    for( int x = size; x > 0; x--){
        numbers[x] = numbers[x-1];
    }

    numbers[0] = number;
    
    size++;

    printFunc(size);

    // -------------------------------------------------------------------------------

    // delete the second element of the array
    printf("The second element is deleted \n");

    if(!(size >= 2))
    {
        printf("Invalid array deletion");
        return 1;
    }

    // left shift array
    for (int x = pos; x < size - 1 ; x++)
    {
        numbers[x] = numbers[x+1];
    }

    // reduce array size
    size--;

    printFunc(size);

    return 0;
}