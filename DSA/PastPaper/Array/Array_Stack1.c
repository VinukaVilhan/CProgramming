#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_OF_BOOKS 100
#define MAX_NAME 50

int main(){

    int num;
    int size = 0;
    char books[MAX_NUMBER_OF_BOOKS][MAX_NAME];

    printf("Stack using array: \n");

    do
    {
        printf("Select the operation.\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Your Response: ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:

            // check if could be inserted
            if (size >= MAX_NUMBER_OF_BOOKS)
            {
                printf("Stack is full");
                exit(1);
            }

            // insert to the beginning
            char book[MAX_NAME];
            printf("Enter the book name: ");
            scanf(" %[^\n]", book);

            strcpy(books[size], book);
            size++;

            printf("Book '%s' pushed successfully!\n", book);

            break;
        case 2: 
            // check if the array is empty
            if(size == 0)
            {
                printf("Stack is empty! Nothing to pop.\n");
                break;
            }

            printf("popped book is %s \n", books[size-1]);

            books[size - 1][0] = '\0';
            size--;
            break;

        case 3: 
            printf("Display books: \n");
            for(int x = 0; x < size; x++)
            {
                printf("%s ", books[x]);
            }
            printf("\n");
            break;
        
        case 4: 
            printf("Peek: \n");
            if(size > 0) {
                printf("Top element is: %s \n", books[size-1]);
            } else {
                printf("Stack is empty!\n");
            }
            break;
           
        case 5: 
            printf("Exiting\n");
            exit(1);

        default:
            break;
        }

    }while(num != 5);
    
    return 0;
}