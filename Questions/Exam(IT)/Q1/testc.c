#include <stdio.h>
#include <string.h>

int main()
{
    int cd[7] = {0}, count = 1000; // Initialize array elements to zero
    int id, LPCount = 0, CPCount = 0, LDCount = 0;

    while (count > 0)
    {
        printf("Enter the Candidate ID: ");
        scanf("%d", &id);
        
        switch(id)
        {
            case 1:
                printf("You have voted for John Smith of Labour Party\n");
                LPCount++;
                cd[0]++;
                break;
                
            case 2:
                printf("You have voted for Nick Sussan in Labour Party\n");
                LPCount++;
                cd[1]++;
                break;

            case 3: 
                printf("You have voted for James Carter in Conservative Party\n");
                CPCount++;
                cd[2]++;
                break;

            case 4: 
                printf("You have voted for Anjelo Martin in Conservative Party\n");
                CPCount++;
                cd[3]++;
                break;
                
            case 5: 
                printf("You have voted for Jolly Deona in Liberal Democrats\n");
                LDCount++;
                cd[4]++;
                break;

            case 6:
                printf("You have voted for Darwin Cameron in Liberal Democrats\n");
                LDCount++;
                cd[5]++;
                break;

            default:
                printf("You have not entered the correct number\n");
                break;
        }

        count = count - 1;
    }
    

    printf("Votes for Labour Party: %d\n", LPCount);
    printf("Votes for Conservative Party: %d\n", CPCount);
    printf("Votes for Liberal Democrats: %d\n", LDCount);

    printf("Votes for John Smith: %d\n", cd[0]);
    printf("Votes for Nick Sussan: %d\n", cd[1]);
    printf("Votes for James Carter: %d\n", cd[2]);
    printf("Votes for Anjelo Martin: %d\n", cd[3]);
    printf("Votes for Jolly Deona: %d\n", cd[4]);
    printf("Votes for Darwin Cameron: %d\n", cd[5]);

    return 0;
}
