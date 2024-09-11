#include <stdio.h>
#include <string.h>

int getLength(char *);

int main()
{
    char string[50];
    int size = 0;
    printf("Enter a string: ");
    scanf("%s", &string);

    size = getLength(string);

    printf("The length of the string is : %d ", size);
}

int getLength(char *string)
{
    int count  = 0;
    for (int x = 0; string[x] != 0; x++ )
    {
        count++;
    }
    return count;
}