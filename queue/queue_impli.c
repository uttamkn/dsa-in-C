#include<stdio.h>
#define SIZE 5

int q[SIZE], r=-1, f=0;

void enqueue(int item) {
    if(r==SIZE-1) {
        printf("Queue overflow\n");
        return;
    }

    q[++r]=item;
}

void dequeue() {
    if(r<f) {
        printf("Queue underflow\n");
        r=-1;
        f=0;
        return; 
    }
    printf("PID: %d was removed\n", q[f++]);
}

void display() {
    if(r<f) {
        printf("Empty\n");
        return;
    }

    for(int i=f; i<=r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void main() {
    int choice, item;
    for(;;) {
        printf("1. Add a process to the queue\n2. Remove a process from the queue\n3. Display all the processes\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter the pid of the process: ");
                scanf("%d", &item);
                enqueue(item);
            }
            break;

            case 2: dequeue();
            break;

            case 3: display();
            break;

            default: return;
        }
    }
}