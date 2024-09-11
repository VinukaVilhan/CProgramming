#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define NUM_PEOPLE 2

int main() 
{
    //initialze arr
    char names[NUM_PEOPLE][MAX_NAME_LENGTH];
    int count = 0;

    while( count < NUM_PEOPLE )
    {
        printf("Enter the name of the person: ");
        fgets(names[count], MAX_NAME_LENGTH, stdin);
        names[count][strcspn(names[count], "\n")] = '\0';
        count++;
    }

    printf("The entered names are:\n");
    for (int i = 0; i < NUM_PEOPLE; i++) {
        printf("%s\n", names[i]);
    }

    printf("%c", names[0][1]);

    return 0;
}
