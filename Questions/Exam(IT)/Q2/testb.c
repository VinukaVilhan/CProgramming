#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int deposit = 10000, years = 10, months = 12;
    float rate = 0.015, total = 0.0;
    char answer[5];

    for( int x = 0; x < years; x++)
    {
        //asking if she wish to keep
        printf("Do you want to keep your money ? type 'YES' if needed. \n");
        scanf("%s", &answer);

        for (int x = 0; answer[x] != '\0'; x++)
        {
            answer[x] = toupper((unsigned char)answer[x]);
        }
        

        if (strcmp(answer, "YES") !=0)
        {
            break;
        }

        for (int y = 0; y < months; y++)
        {
            total += deposit * rate;
            printf("Total of year %d month %d is : %.2f\n", x+1, y+1, total);
        }
        
    }

    return 0;
}