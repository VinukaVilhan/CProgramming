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
    int empNumber = 100;
    Employee *employees = (Employee*) calloc ( empNumber, sizeof(Employee)) ;

    
    for(int x = 0 ; x < empNumber; x++)
    {
        printf("Enter the employee ID: ");
        scanf("%d", &employees[x].id);
        printf("Enter the NIC of employee: ");
        scanf("%llu", &employees[x].NIC);
        printf("Enter the name of the employee: ");
        while(getchar() != '\n');
        fgets( employees[x].name,MAX_NAME , stdin);
        employees[x].name[strcspn(employees[x].name, "\n")] = '\0';

        printf("Enter the address of the employee: ");
        fgets(employees[x].address, MAX_ADDRESS, stdin);
        employees[x].address[strcspn(employees[x].address, "\n")]= '\0';

        printf("Enter the Date of Birth of employee: ");
        fgets(employees[x].dob, 50, stdin);
        employees[x].dob[strcspn(employees[x].dob, "\n")]= '\0';

        printf("Enter the depaertment of employee: ");
        fgets(employees[x].dept, 50, stdin);
        employees[x].dept[strcspn(employees[x].dept, "\n")]='\0';

        printf("\n");


        printf("The employee ID is: %d \n", employees[x].id);
        printf("The employee NIC is: %llu \n", employees[x].NIC);
        printf("The employee name is: %s \n", employees[x].name);
        printf("The employee address is: %s \n", employees[x].address);
        printf("The employee date of birth is: %s \n", employees[x].dob);
        printf("The employee department is: %s \n", employees[x].dept);

        printf("\n");
    }
    
    return 0;
}