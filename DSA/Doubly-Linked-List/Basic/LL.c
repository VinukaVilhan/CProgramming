#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;    
    struct node* prev;
} Node;


Node* createNode(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int main()
{
    // create a new node
    Node* first = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* fourth = createNode(40);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = NULL;

    // printing the linked list
    printf("The linked list is printed: ");
    Node* temp = first;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}