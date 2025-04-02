#include <stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];

int top = -1;

void push(int x){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
        return;
    }
    A[++top] = x;
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    top--;
}


int Top(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return A[top];
}

void print(){
    int i;
    printf("Stack: ");
    for(int x = 0; x < top; x++){
        printf("%d ", A[x]);
    }
    printf("\n");
}

int main(){

    push(1); print();
    push(2); print();
    push(3); print();
    push(4); print();
    pop(); print();
    top = Top();
    printf("%d\n", top);
    print();
    
    return 0;
}