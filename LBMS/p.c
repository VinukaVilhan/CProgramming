#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_NAME_LENGTH 50
#define MAX_ISBN_LENGTH 50


int num_of_books = 0;

//struct initialization
typedef struct 
{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
    int year;
}Book;


void addBook(Book *);
void displayBooks(Book *);
Book *searchBook();

int main()
{
    int input = -1;
    Book *books = NULL;
    while(input != 0)
    {
        printf(" Welcome to the library management system.\n Please select your choice and enter the number.\n");
        printf(" 0. Exit the program \n 1. Add a book \n 2. Search for a book \n 3. Display all Book \n 4. Sort Book \n 5. Exit the progam \n");

        scanf("%d", &input);

        switch(input)
        {
            case 0: 
                printf("Exiting the programme.\n");
                break;

            case 1:
                printf("You are adding a book.\nPlease enter the details: \n");
                //iniitalizing a struct array
                num_of_books++;
                books = (Book*) realloc(books, num_of_books * sizeof(Book));

                if(books == NULL)
                {
                    printf("Memory allocation has failed\n");
                    return 1;
                }
                addBook(&books[num_of_books - 1]);
                break;
            
            case 2:
                printf("You are searching for a book.\nEnter the ISBN of the book: ");
                Book *foundBook= searchBook(&books[0]);
                if(foundBook != NULL)
                {
                    printf("The book title: %s\nThe author name: %s\nThe ISBN number: %s\n The published year: %d\n", foundBook->title, foundBook->author, foundBook->isbn, foundBook-> year);
            
                }
                else
                {
                    printf("Book not found\n");
                }
                break;
                
            case 3:
                printf("You are diplaying all the books.\n");
                displayBooks(&books[0]);
                break;
            default:
                printf("Wrong selection\n");
                break;
        }

    }

    free(books);
    return 0;
}

void addBook(Book *book)
{
    getchar(); // Clear the newline character from the input buffer
    printf("Enter the title of the book: ");
    fgets(book->title, MAX_TITLE_LENGTH ,stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    printf("Enter the author's name: ");
    fgets(book->author, MAX_AUTHOR_NAME_LENGTH, stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Enter the ISBN of the book: ");
    fgets(book->isbn, MAX_ISBN_LENGTH, stdin);
    book->isbn[strcspn(book->isbn, "\n")] = '\0';

    printf("Enter the year the book was published: ");
    scanf("%d", &book->year);
    getchar(); // Clear the newline character from the input buffer
}


void displayBooks(Book *books)
{
    for(int x = 0; x < num_of_books; x++)
    {
        printf("The title of the book is : %s\n", books[x].title);
        printf("The author of the book is : %s\n", books[x].author);
        printf("The ISBN of the book is : %s\n", books[x].isbn);
        printf("The year the book has been published is : %d\n", books[x].year);
    }
}


Book *searchBook(Book *books)
{
    char name[MAX_ISBN_LENGTH];
    printf("Enter the ISBN number of the book: ");
    scanf("%s", &name);
    getchar();

    for(int x = 0; x < num_of_books; x++)
    {
        if(strcmp(name, books[x].isbn)==0)
        {
            return &books[x];
        }
    }
    return NULL;

}