#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 30

typedef struct 
{
    long NIC;
    char Name[20];
    char gender;
    char guardianName[20];
    long number;
}Student;

int main()
{
    Student student1;
    printf("Enter student NIC number: ");
    scanf("%ld", &student1.NIC);
    getchar();
    
    printf("Enter student name: ");
    fgets( student1.Name, MAX_NAME_LENGTH, stdin);
    student1.Name[strcspn(student1.Name, "\n")] = 0;
    
    printf("Enter the gender: ");
    scanf("%c", &student1.gender);
    student1.gender = toupper((unsigned char)student1.gender);
    getchar();
    
    printf("Enter the guardian name: ");
    fgets(student1.guardianName, MAX_NAME_LENGTH, stdin);
    student1.guardianName[strcspn(student1.guardianName, "\n")] = 0;

    printf("Enter the phone number: ");
    scanf("%ld", &student1.number);

    // Print to verify the inputs
    printf("\nStudent Information:\n");
    printf("NIC: %ld\n", student1.NIC);
    printf("Name: %s\n", student1.Name);
    printf("Gender: %c\n", student1.gender);
    printf("Guardian Name: %s\n", student1.guardianName);
    printf("Phone Number: %ld\n", student1.number);

    return 0;
}