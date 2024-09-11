#include <stdio.h>
#include <string.h>
#include <ctype.h>

//predefined struct for students
typedef struct
{
    int id;
    char name[50];
    int age;
    char school[50];
}Student;

//define the array of students
Student students [] = {
    {100, "Vinuka", 12, "MSC"},
    {200, "Bob", 18, "High School B"},
    {300, "Charlie", 16, "High School C"},
    {400, "Diana", 17, "High School D"},
};

//predefined struct for buses
typedef struct
{
    char code;
    char bus_stop[40];
    int distance;
}Bus;

//array of buses
Bus buses[] = {
    {'A', "Katubedda", 21},
    {'B', "Ratmalana", 16},
    {'C', "Mt. Lavinia", 15},
    {'D', "Dehiwala", 10}
};

//functions
const char* checkStudent(int );
int checkDistance(char );

int main()
{ 
    //student checking
    int id;
    printf("Enter the student ID is you're a student: ");
    scanf("%d", &id);
    const char* result = checkStudent(id);
    printf("%s", result);

    char code;
    printf("Enter the origin bus stop code: ");
    scanf(" %c", &code);

    code = toupper((unsigned char)code);

    int distance = checkDistance(code);

    if(distance == -1)
    {
        printf("Invalid Code. Try again");
        return 1;
    }

    //pay as you travel fee
    int cost = distance * 5;

    printf("The cost is: %d", cost);
    return 0;
}

const char* checkStudent (int id)
{
    //finding the size of teh array
    int size = sizeof(students)/ sizeof(students[0]);

    for(int x = 0; x < size; x++)
    {
        if ( students[x].id == id)
        {
            return "Free pass\n";
        }
    }
    return "No free pass\n";
}

int checkDistance(char code)
{
    int size = sizeof(buses)/ sizeof(buses[0]);
    for(int x = 0; x < size; x++)
    {
        if (buses[x].code = code)
        {
            return buses[x].distance;
        }
    }
    return -1;
}
