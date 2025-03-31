#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

int main() {
    // create a new node
    Node* node = (Node*) malloc(sizeof(Node));

    // node = NULL;

    // assigning data
    node->data = 10;

    // creating a second node
    Node* node2 = (Node*) malloc(sizeof(Node));

    node2->data = 20;

    // creating 3rd node
    Node* node3 = (Node*) malloc(sizeof(Node));

    node3->data = 30;

    // linking the nodes
    node->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // printing the linked list
    printf("The linked list is printed: ");
    Node* temp  = node;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    return 0;
}