#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertAtBegining(int number){
    Node* created = createNode(number);

    if (created ==  NULL)
    {
        return;
    }

    if (head == NULL){
        head = created;
        tail = created;
        return;
    }

    created->next = head;
    head->prev = created;
    head = created;

}

void insertAtLocation(int value, int position)
{

    if (position == 1)
    {
        insertAtBegining(value);
        return;
    }
        
    Node* temp = head;
    Node* afterCreated;

    Node* created = createNode(value);

    if(created == NULL)
    {
        return;
    }

    for (int x = 1; x < position - 1 && temp!= NULL; x++)
    {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(created);
        return;
    }

    afterCreated = temp->next;

    created->next = afterCreated;

    created->prev = temp;

    temp->next = created;

    if(afterCreated != NULL)
    {
        afterCreated->prev = created;
    }else{
        tail = created;
    }

}

void insertAtEnd(int value){
    
    Node* created = createNode(value);

    if(created == NULL)
    {
        return;
    }

    if (head == NULL) {
        head = created;
        tail = created;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp=temp->next;
    }

    temp->next = created;
    created->prev = temp;
    created->next = NULL;

    tail = created;

}

void DeleteAtBegining()
{
    Node* temp = head;

    if(head == NULL)
    {
        return;
    }

    head = temp->next;

    head->prev = NULL;

    free(temp);

}

void DeleteAtEnd()
{
    Node* temp = head;

    if(temp == NULL)
    {
        return;
    }

    if(temp->next == NULL)
    {
        free(head);
        head = tail =NULL;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    tail = temp->prev;

    tail->next = NULL;

    free(temp);
}

void DeleteAtLocation(int pos){

    if (pos < 0 || head == NULL)
    {
        return;
    }

    Node* temp = head;

    if (pos == 1)
    {
        DeleteAtBegining();
        return;
    }

    for (int x = 1; x < pos - 1 && temp != NULL ; x++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if(temp->next == NULL)
    {
        DeleteAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}



void printList(){
    Node* temp = head;

    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(){
    Node* temp = head;
    Node* next;

    while(temp!=NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;
    tail = NULL;
}

int main(){
   

    insertAtBegining(1);

    printList();

    insertAtBegining(2);

    printList();

    insertAtBegining(3);

    printList();

    insertAtLocation(7,3);

    printList();

    insertAtEnd(4);

    printList();

    DeleteAtBegining();

    printList();

    DeleteAtLocation(1);

    printList();

    DeleteAtEnd();

    printList();

    freeList();

    return 0;
}