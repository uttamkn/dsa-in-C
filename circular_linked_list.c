#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *last=NULL;

void insertRear(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;
    if(last==NULL) {
        last=temp;
        last->link=last;
        return;
    }
    temp->link=last->link;
    last->link=temp;
    last=temp;
}

void insertFront(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;
    if(last==NULL) {
        last=temp;
        last->link=last;
        return;
    }
    temp->link=last->link;
    last->link=temp;
}

void deleteFront() {
    if(last==NULL) {
        printf("underflow\n");
        return;
    }
    if(last->link==last) {
        free(last);
        last=NULL;
        return;
    }
    struct node *front=last->link;
    last->link=front->link;
    free(front);
    front=NULL;
}

void deleteRear() {
    if(last==NULL) {
        printf("underflow\n");
        return;
    }
    if(last->link==last) {
        free(last);
        last=NULL;
        return;
    }
    struct node *racer=last->link;
    while (racer->link!=last) racer=racer->link;
    racer->link=last->link;
    free(last);
    last=racer;
}

void display() {
    if(last==NULL) {
        printf("empty\n");
        return;
    }

    struct node *racer=last->link;

    do {
        printf("%d-->", racer->data);
        racer=racer->link;
    }while(racer!=last->link);
    printf("\n");
}

int main() {
    insertFront(12);
    display();
    insertFront(18);
    display();
    insertRear(32);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}
