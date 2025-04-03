#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* head = NULL;

int getLength() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


Node* createNode(int value){

    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(int value){

    // create a node
    Node* newNode = createNode(value);

    if (newNode == NULL)
    {
        return;
    }

    if(head == NULL)
    {
        head = newNode;
    }else{
        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBegining(int value){

    Node* newNode = createNode(value);

    Node* temp = head;

    if(head == NULL){
        head = newNode;
        head->next = NULL;
    }

    newNode->next = temp;
    newNode->data = value;
    head = newNode;
}

void insertAtLocation(int value, int position){

    int length = getLength();

    if (position >  length){
        printf("Invalid position!\n");
        return;
    }

    Node* newNode = createNode(value);

    Node* temp = head;
    Node* new;

    if(head == NULL)
    {
        return;
    }

    for (int x = 1; x < position - 1; x++){
        temp = temp->next;
    }

    new = temp->next;

    temp->next = newNode;
    newNode->next = new;
}


void deleteAtBegining(){

    if(head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    Node* temp = head;

    head  = temp->next;

    free(temp);

    return;
}


void deleteAtEnd(){

    if(head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node successfully.\n");
        return;
    }


    Node* temp = head;
    Node* new;
    
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    new = temp->next->next;

    free(new);

    temp->next = NULL;

}

void deleteAtLocation(int position)
{

    Node* temp = head;
    Node* new;

    if(head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    for (int x = 1; x < position - 1; x++)
    {
        temp = temp->next;
    }

    new = temp->next->next;

    temp->next = new;

    free(temp);

}
    
    

void printList()
{
    Node* temp =  head;

    if(temp == NULL)
    {
        printf("Empty linked list");
        return;
    }

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(){
    Node* temp;

    while(head != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
}

int main(){

    insertAtEnd(1);
    insertAtEnd(2);

    insertAtBegining(4);
    insertAtBegining(5);

    insertAtLocation(0, 2);

    printList();

    deleteAtBegining();

    printf("After deleting at the begining \n");

    printList();

    printf("After deleting at the end \n");

    deleteAtEnd();

    printList();

    printf("After deleting at location \n");

    deleteAtLocation(1);

    printList();

    freeList();

    return 0;
}