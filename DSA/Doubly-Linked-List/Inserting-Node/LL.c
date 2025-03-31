#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;    
    struct node* prev;
} Node;

Node* head;

Node* createNode(int Number);

void insertAthead(int number){
    Node* newNode = createNode(number);

    // empty list
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // non-empty list
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}

Node* createNode(int number)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = number;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void print(){
    Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

void printReverse()
{
    Node* temp = head;

    if(temp == NULL)
    {
        return;
    }

    // go to the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Reverse: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    insertAthead(1);
    insertAthead(2);
    insertAthead(3);

    print();

    printReverse();
    return 0;
}