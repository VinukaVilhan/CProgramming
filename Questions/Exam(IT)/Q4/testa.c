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
    Employee emp1;
    printf("Enter the employee ID: ");
    scanf("%d", &emp1.id);
    printf("Enter the NIC of employee: ");
    scanf("%llu", &emp1.NIC);
    printf("Enter the name of the employee: ");
    while(getchar() != '\n');
    fgets( emp1.name,MAX_NAME , stdin);
    emp1.name[strcspn(emp1.name, "\n")] = '\0';

    printf("Enter the address of the employee: ");
    fgets(emp1.address, MAX_ADDRESS, stdin);
    emp1.address[strcspn(emp1.address, "\n")]= '\0';

    printf("Enter the Date of Birth of employee: ");
    fgets(emp1.dob, 50, stdin);
    emp1.dob[strcspn(emp1.dob, "\n")]= '\0';

    printf("Enter the depaertment of employee: ");
    fgets(emp1.dept, 50, stdin);
    emp1.dept[strcspn(emp1.dept, "\n")]='\0';


    printf("The employee ID is: %d \n", emp1.id);
    printf("The employee NIC is: %llu \n", emp1.NIC);
    printf("The employee name is: %s \n", emp1.name);
    printf("The employee address is: %s \n", emp1.address);
    printf("The employee date of birth is: %s \n", emp1.dob);
    printf("The employee department is: %s \n", emp1.dept);
    return 0;
}