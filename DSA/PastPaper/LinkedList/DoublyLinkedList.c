#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Queue {
    Node* front;  
    Node* rear;
} Queue;

// Initialize queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// insert in the back
void enqueue(Queue* queue, int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // if the queue is empty
    if(queue->front == NULL){
        queue->front = newNode;
        queue->rear = newNode;
    }
    else{
        queue->rear->next = newNode;
        newNode->prev = queue->rear;
        queue->rear = newNode;
    }

    printf("New node is: %d \n", newNode->data);
}

void dequeue(Queue* queue)
{
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    // taken out from the front
    Node* temp = (Node*) malloc(sizeof(Node));

    temp = queue->front;
    queue->front = temp->next;
    queue->front->prev = NULL;

    printf("Dequeued: %d\n", temp->data);

    free(temp);
}

void display(Queue* queue)
{
    Node* temp = queue->front;

    if(temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
    return;
}

int main()
{
    // initialize stack

    Queue queue;
    initQueue(&queue);

    int num;
    printf("Stack usign singly linked list\n");
    
    do{
        
        printf("1.Enqueue()\n2.Dequeue()\n3.Display\n4.Exit\n");
        printf("Enter the number: ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            int val;
            scanf("%d", &val);

            enqueue(&queue, val);
            break;
        case 2:
            printf("Dequeue\n");
            dequeue(&queue);
            break;
        case 3:
            printf("Display: \n");
            display(&queue);
            break;
        case 4:
            printf("exiting\n");
            break;
        default:
            break;
        }
    }while(num!=4);
    return 0;
}