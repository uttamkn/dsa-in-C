#include <stdio.h>
#define SIZE 4
int top=-1;
int stack[SIZE];

void push(int item) {
    if(top==SIZE-1) {
        printf("stack overflow\n");
        return;
    }
    stack[++top]=item;
}

void pop() {
    if(top==-1) {
        printf("stack underflow\n");
        return;
    }
    top--;
}

void display() {
    if(top==-1) {
        printf("Empty\n");
        return;
    }

    for(int i=top; i>=0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    
    for(;;) {
        printf("Enter a choice:\n 1. push\n 2. pop\n 3. display\n 4. exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: {
            printf("Enter the item to be added: ");
            scanf("%d", &item);
            push(item);
        }
        break;
        
        case 2: pop();
        break;

        case 3: display();
        break;

        default: return 0;
        }
    }
    return 0;
}