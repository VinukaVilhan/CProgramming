#include <stdio.h>
#include <string.h>


int getLength(char *);
int getSum(int);
void reverseString(char *, char *, int);

int main()
{
    char string[50];
    char reverse[50];
    int size = 0, sum, number;
    printf("Enter a string: ");
    scanf("%s", string);

    size = getLength(string);

    reverseString(reverse, string, size);

    printf("The reversed string: %s\n", reverse);

    printf("Enter the number: ");
    scanf("%d", &number);
    sum = getSum(number);


    strcat(reverse, string);

    printf("The new password: %s%d",reverse, sum);

    
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

int getSum(int number)
{
    if(number == 0)
    {
        return 0;
    }
    else
    {
        return number + getSum(number - 1);
    }

}

void reverseString(char *reverse, char *string, int size)
{
    int c = 0;
    while(size > 0)
    {
        reverse[c] = string[size - 1];
        c++;
        size--;
    }

    reverse[c] = '\0';
    
}