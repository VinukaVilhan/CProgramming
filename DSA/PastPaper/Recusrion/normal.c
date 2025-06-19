#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c \n", source, destination);
        return;
    }
    else
    {
        towerOfHanoi(n-1, source, auxiliary, destination);

        printf("Move disk from %c to %c \n", source, destination);

        towerOfHanoi(n-1, auxiliary, destination, source);
    }
}

int main()
{
    printf("Tower of hanoi\n");
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    towerOfHanoi(num, 'A', 'C', 'B');
    return 0;
}