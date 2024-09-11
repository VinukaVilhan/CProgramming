//dynamic arrays to store numbers and names

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

int *numbers;
char (*names)[MAX_NAME_LENGTH];

int main()
{
    numbers = NULL;
    int n_input, count = 0;
    while(true)
    {
        printf("Enter numbers (press 0 to exit):");
        scanf("%d", &n_input);
        getchar();
        if ( n_input == 0)
        {
            break;
        }
        count++;

        numbers = (int*) realloc(numbers, count * sizeof(int));
        numbers[count - 1] = n_input;
    }

    printf("The entered numbers are:\n");
    for(int x = 0; x < count; x++)
    {
        printf("%d ", numbers[x]);
    }

    free(numbers);
    printf("\n");

    //enter names
    names = NULL;
    count = 0;
    char name[MAX_NAME_LENGTH];
    while(true)
    {
        printf("Enter the name (Type 'DONE' to stop): ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = '\0';

        if(strcmp( name, "DONE") == 0)
        {
            break;
        }
        count++;
        names = (char (*) [MAX_NAME_LENGTH]) realloc(names, count * MAX_NAME_LENGTH * sizeof(char));
        strcpy(names[count-1], name);
        
    }

    //print the name
    printf("The entered names are:\n");
    for(int x = 0; x < count; x++)
    {
        printf("%s\n", names[x]);
    }

    free(names);
    
    return 0;
}