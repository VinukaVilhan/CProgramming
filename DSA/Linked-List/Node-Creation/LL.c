#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;    
} Node;


Node* createNode(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main(){

    // create a new node
    Node* first = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    first->next = second;
    second->next = third;
    third->next = NULL;

    // printing the linked list
    printf("The linked list is printed: ");
    Node* temp = first;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    return 0;
}