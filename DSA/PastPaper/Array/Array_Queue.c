// A Queue based on an Array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50

int main()
{
    int num;
    int front = -1, rear = -1;
    char queue[MAX_CUSTOMERS][MAX_NAME_LENGTH];

    do{
        printf("Enter command: \n1.Enqueue \n2.Dequeue\n3.Result\n4.Exit\nYour choice: ");
        scanf("%d", &num);
        printf("You entered: %d\n", num);

        switch(num){
            case 1:{
                
                printf("Enter customer name to enqueue: \n");
                char name[MAX_NAME_LENGTH];
                scanf("%s", &name);
          

                if (rear = MAX_CUSTOMERS - 1) {
                    printf("Queue is full\n");
                    exit(1);
                }

                if(front == -1){
                    front = 0;
                }

                rear++;
                strcpy(queue[MAX_CUSTOMERS], name);
                printf("Value enqueued successfully: %s \n", name);
                break;
            }
            case 2:{
                if(front ==1 || front > rear){
                    printf("Queue is empty");
                    exit(0);
                }

                printf("Dequeued value: %s\n", queue[front]);
                front++;

                if(front > rear)
                {
                    front = rear = -1;
                }
            
                break;
            
            }
            case 3:{
                printf("The resulting Queue: ");

                if (front == -1 || front > rear) 
                {
                    printf("Queue is empty!\n");
                    break;
                }
                
                int x = front;
                while(x <= rear){
                    printf("%s ", queue[x]);
                    x++;
                }

                printf("\n");

                break;
            }
            case 4:{
                printf("Exiting the program");
                exit(0);
            }
            default:{
                printf("Invalid command\n");
                exit(1);
            }
        }
    }
    while (num != 4);

    return 0;
}