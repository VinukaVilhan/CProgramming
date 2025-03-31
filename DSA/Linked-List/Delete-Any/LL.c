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


void delete(int number){
    Node* temp1 = head;

    // head node
    if (number == 0)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    int i;
    for(int i = 0; i < number - 1 && temp1 != NULL; i++)
    {
        temp1 = temp1->next;
    }

    // deleting nodes
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;

    free(temp2);
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

void freeList()
{
    Node* temp = head;
    Node* nextNode;
    while (temp != NULL)
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    head = NULL;
}

int main(){


    int num; 

    head = NULL;
    insert(1,0);
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,1);

    print();

    printf("Enter the position you want to delete: ");
    scanf("%d", &num);

    delete(num);

    print();

    freeList();
    return 0;
}