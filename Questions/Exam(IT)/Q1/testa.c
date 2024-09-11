#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NATIONALITY_LENGTH 50

typedef struct
{
    int day;
    int month;
    int year;
}Date;


typedef struct
{
    char name[MAX_NAME_LENGTH];
    char nationality[MAX_NATIONALITY_LENGTH];
    long long unsigned NIC;
    Date dob;
}Voter;

int main()
{
    Voter voter1;
    printf("Enter the name: ");
    fgets( voter1.name, MAX_NAME_LENGTH, stdin);
    voter1.name[strcspn(voter1.name, "\n")] = '\0';

    printf("Enter the Date of birth: \n");
    printf("Enter the date: ");
    scanf("%d", &voter1.dob.day);
    getchar();
    printf("Enter the month: ");
    scanf("%d", &voter1.dob.month);
    getchar();
    printf("Enter the year: ");
    scanf("%d", &voter1.dob.year);
    getchar();

    //while(getchar() != '\n');

    printf("Enter the nationality: ");
    fgets(voter1.nationality, MAX_NATIONALITY_LENGTH, stdin);
    voter1.nationality[strcspn(voter1.nationality, "\n")]='\0';

    printf("Enter the NIC number: ");
    scanf("%llu", &voter1.NIC);

    //dispaly info
    printf("The name is : %s \n", voter1.name);
    printf("The Date of birth is:  %d-%d-%d \n", voter1.dob.year, voter1.dob.month, voter1.dob.day);
    printf("The nationality is: %s \n", voter1.nationality);
    printf("The NIC is %llu \n", voter1.NIC);
    return 0;
}