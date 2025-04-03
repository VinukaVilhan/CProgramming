#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int arr[SIZE];

int front = -1, rear = -1;

bool IsEmpty(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return true;
    }
    else 
    {
        return false;
    }
}

bool IsFull(){

    if (rear == SIZE -1 )
    {
        printf("Queue is full.\n");
        return true;
    }

    return false;
    
}

void Enqueue(int number){

    // check if the queue is full
    if(IsFull())
    {
        return;
    } else if (IsEmpty()){
        front = rear = 0;
    }else{
        rear++;
    }

    arr[rear] = number;

}


void Dequeue()
{
   if (IsEmpty()){
    return;
   } 
   else if(front == rear){
    front = rear = -1;
   }
   else{
    front++;
   }
}

void PrintQueue(){
    if(IsEmpty()){
        return;
    }

    printf("Queue: ");

    for(int x = front; x <= rear; x++)
    {
        printf("%d ", arr[x]);
    }
    printf("\n");
}

void Peek(){
    printf("The first element of the array.\n");

    if(IsEmpty()){
        return;
    }

    printf("The front element is %d \n", arr[front]);
}

int main()
{

    // Dequeue();

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);

    PrintQueue();

    Peek();

    Dequeue();
    Dequeue();


    PrintQueue();

    return 0;
}