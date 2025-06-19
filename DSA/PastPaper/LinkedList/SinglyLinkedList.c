// stack
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
} Stack;

void push(Stack* stack, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode; 
    printf("Pushed %d onto the stack.\n", data);
}

void pop(Stack* stack)
{
    if (stack->top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }

    Node* temp = stack->top;
    stack->top = temp->next;

    printf("Popped :%d\n", temp->data);
    free(temp);
    
}

void display(Stack* stack)
{
    if (stack->top == NULL) {
        printf("Stack is empty!.\n");
        return;
    }

    Node* temp = stack->top;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

void initStack(Stack *stack)
{
    stack->top = NULL;
}

int main()
{
    // initialize stack

    Stack stack;
    initStack(&stack);

    int num;
    printf("Stack usign singly linked list\n");
    
    do{
        
        printf("1.Push()\n2.Pop()\n3.Display\n4.Exit\n");
        printf("Enter the number: ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("Enter the value: ");
            int val;
            scanf("%d", &val);

            push(&stack, val);
            break;
        case 2:
            printf("Popping\n");
            pop(&stack);
            break;
        case 3:
            printf("Display: \n");
            display(&stack);
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