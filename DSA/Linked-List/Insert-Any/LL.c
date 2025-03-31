#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;    
} Node;

Node* head;

// insert at any position
void insert(int data, int position){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // head position
    if (position == 0){
        newNode->next = head;
        head = newNode;
        return;
    }

    // in any other position
    Node* temp = head;
    for(int x = 0; x < position - 1 && temp != NULL; x++)
    {
        temp = temp->next;
    }

    // position bounds
    if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    // insert the new node at correct position
    newNode->next = temp->next;
    temp->next = newNode;

}

void print()
{
    Node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    head = NULL;
    insert(1,0);
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,1);

    print();
    return 0;
}