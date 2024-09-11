#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    long NIC;
    int visit;

}Visitors;

int main()
{
    int number = 1, count = 0;
    // array of structs
    Visitors *visits = (Visitors *)malloc(number * sizeof(Visitors));
    if(visits == NULL)
    {
        printf("Memory allocation has failed \n");
        return 1;
    }

    while (true)
    {
        printf("Enter the NIC number or 0 to exit: ");
        scanf("%ld", &number);

        if (number == 0)
        {
            break;
        }

        bool found = false;

        if (count != 0)
        {
            for(int x = 0; x < count; x++)
            {
                if(visits[x].NIC ==  number)
                {
                    printf("The Visitor with NIC %d have visited %d times \n", visits[x].NIC, visits[x].visit);
                    found = true;
                    visits[x].visit ++;
                    break;
                } 
            }
        }
        else
        {
            if(!found || count == 0)
            {
                count ++;
                visits = (Visitors *) realloc(visits, count * sizeof(Visitors));

                if(visits == NULL)
                {
                    printf("Memory allocation has failed \n");
                    return 1;
                }

                //store the NIC and initialize visit count as 1
                visits[count - 1].NIC = number;
                visits[count - 1].visit = 1;

                printf("The Visitor with NIC %ld is visiting for 1st time \n", visits[count-1].NIC );

            }   
        }
    }

    free(visits);
    return 0;
}