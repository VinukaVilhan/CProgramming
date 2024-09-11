#include <stdio.h>
#include <stdlib.h>

//struct initialization
typedef struct 
{
    int score;
}Marks;

int main()
{
    //array initialization
    Marks *students;

    int number, input;
    long long total = 0;
    float average;

    printf("Enter the number of students: ");
    scanf("%d", &number);

    students = (Marks *) calloc( number , sizeof(Marks));
    
    if(students == NULL)
    {
        printf("Memory allocation has failed \n");
        return 1;
    }

    printf("Enter the marks: \n");

    for(int x = 0; x < number; x++)
    {
        scanf("%d", &input);
        students[x].score = input;
    }

    //get the total
    for(int x = 0; x < number; x++)
    {
        total += students[x].score;
    }

    average = (float)total / number;

    printf("Tne average is : %.2f", average);

    free(students);
    return 0;
}