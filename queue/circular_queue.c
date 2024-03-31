#include<stdio.h>
#define SIZE 5
int q[SIZE], r=-1, f=0, count=0;

void enqueue(int item) {
    if(count==SIZE) {
        printf("Queue overflow\n");
        return;
    }
    r=(r+1)%SIZE;
    q[r]=item;
    count++;
}

void dequeue() {
    if(count==0) {
        printf("Queue underflow\n");
        return;
    }
    printf("PID: %d was removed\n\n", q[f]);
    f=(f+1)%SIZE;
    count--;
}

void display() {
    if(count==0) {
        printf("empty\n");
        return;
    }
    for(int i=0; i<count; i++) {
        printf("%d ", q[(f+i)%SIZE]);
    }
    printf("\n");
}

void main() {
    int choice, item;

    for(;;) {
        printf("1. Add a process\n2. Remove a process\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter pid: ");
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