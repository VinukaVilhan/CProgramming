#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;    
} Node;

Node* head;

// insert at begining

void insert(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int main()
{
    head = NULL; // Initialize head to NULL
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);
    for(int x = 0; x < n; x++){
        int data;
        printf("Enter the data for node %d: ", x + 1);
        scanf("%d", &data);
        insert(data);
    }

    // printing the linked list
    printf("The linked list is printed: ");
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // free the allocated memory
    temp = head;
    Node* nextNode;
    while (temp != NULL)
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    return 0;
}