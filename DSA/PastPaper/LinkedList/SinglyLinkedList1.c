// queue
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

void initQueue(Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(queue->front == NULL && queue->rear == NULL){
        queue->front = newNode;
        queue->rear = newNode;
    }
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue)
{
    if(queue == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = (Node*) malloc(sizeof(Node));

    temp = queue->front;

    queue->front = temp->next;
    temp->next = NULL;

    printf("Dequeud: %d\n", temp->data);

    free(temp);

}

void display(Queue* queue)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode = queue->front;

    while(newNode != NULL)
    {
        printf("%d ", newNode->data);
        newNode = newNode->next;
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
    printf("Queue usign singly linked list\n");
    
    do{
        
        printf("1.Enqueue()\n2.Dequeue()\n3.Display\n4.Exit\n");
        printf("Enter the number: ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("Enter the value: ");
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