#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_ADDRESS 50

typedef struct
{
    int id;
    long long unsigned NIC;
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char dob[50];
    char dept[50];
}Employee;

int main()
{
    int number;
    
    printf("Enter number of emps: ");
    scanf("%d", &number);

    //array of structs
    Employee *emps = (Employee*) calloc(number, sizeof(Employee));
    
    for(int x = 0; x < number; x++)
    {
        printf("Enter the employee ID: ");
        scanf("%d", &emps[x].id);
        printf("Enter the NIC of employee: ");
        scanf("%llu", &emps[x].NIC);
        printf("Enter the name of the employee: ");
        while(getchar()!='\n');
        fgets( emps[x].name,MAX_NAME , stdin);
        emps[x].name[strcspn(emps[x].name, "\n")] = '\0';

        printf("Enter the address of the employee: ");
        fgets(emps[x].address, MAX_ADDRESS, stdin);
        emps[x].address[strcspn(emps[x].address, "\n")]= '\0';

        printf("Enter the Date of Birth of employee: ");
        fgets(emps[x].dob, 50, stdin);
        emps[x].dob[strcspn(emps[x].dob, "\n")]= '\0';

        printf("Enter the depaertment of employee: ");
        fgets(emps[x].dept, 50, stdin);
        emps[x].dept[strcspn(emps[x].dept, "\n")]='\0';

        printf("\n");   
    }

    int newEmps = 10;

    //realloc memory
    emps = (Employee*) realloc(emps, newEmps *  sizeof(Employee));

    for(int x = 0; x < newEmps; x++)
    {
        printf("Enter the employee ID: ");
        scanf("%d", &emps[x].id);
        printf("Enter the NIC of employee: ");
        scanf("%llu", &emps[x].NIC);
        printf("Enter the name of the employee: ");
        while(getchar()!='\n')
        fgets( emps[x].name,MAX_NAME , stdin);
        emps[x].name[strcspn(emps[x].name, "\n")] = '\0';

        printf("Enter the address of the employee: ");
        fgets(emps[x].address, MAX_ADDRESS, stdin);
        emps[x].address[strcspn(emps[x].address, "\n")]= '\0';

        printf("Enter the Date of Birth of employee: ");
        fgets(emps[x].dob, 50, stdin);
        emps[x].dob[strcspn(emps[x].dob, "\n")]= '\0';

        printf("Enter the depaertment of employee: ");
        fgets(emps[x].dept, 50, stdin);
        emps[x].dept[strcspn(emps[x].dept, "\n")]='\0';

        printf("\n");   
    }


    free(emps);
    return 0;
}