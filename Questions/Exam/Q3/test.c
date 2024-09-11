#include <stdio.h>
#include <stdlib.h>

//dynamic array
int *arr;
int size = 2;

int main() {

long number;

//allocate memory for array
arr = (int *)malloc(size * sizeof(int));
if(arr == NULL)
{
    printf("Memory allocation failed \n");
    return 1;
}

for(int x = 0; x < size; x++)
{
    printf("Enter the NIC number: ");
    scanf("%d", &number);
}

//print the values
for(int x = 0; x < size; x++)
{
    printf("NIC number for employee %d: %d \n", x, arr[x]);
}

free(arr);

return 0;

}