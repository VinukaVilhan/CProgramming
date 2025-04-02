#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node* top = NULL;

void push(int value){

    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;

    newNode->next = top;

    top = newNode;
}

void pop(){
    Node* temp;
    if(top == NULL) return;

    temp = top;
    top = top->next;
    free(temp);
}


void print()
{
    Node* temp = top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    push(1);
    push(2);
    push(3);
    print();

    pop();
    print();

    return 0;
}