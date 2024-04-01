#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *last=NULL;

void insertRear(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->next=NULL;
    if(last==NULL) {
        last=temp;
        last->next=last;
        return;
    }
    temp->next=last->next;
    last->next=temp;
    last=temp;
}

void insertFront(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->next=NULL;
    if(last==NULL) {
        last=temp;
        last->next=last;
        return;
    }
    temp->next=last->next;
    last->next=temp;
}

void deleteFront() {
    if(last==NULL) {
        printf("underflow\n");
        return;
    }
    if(last->next==last) {
        free(last);
        last=NULL;
        return;
    }
    struct node *front=last->next;
    last->next=front->next;
    free(front);
    front=NULL;
}

void deleteRear() {
    if(last==NULL) {
        printf("empty\n");
        return;
    }
    if(last->next==last) {
        free(last);
        last=NULL;
        return;
    }
    struct node *newLast=last->next;
    while(newLast->next!=last) newLast=newLast->next;
    newLast->next=last->next;
    free(last);
    last=newLast;
}

void display() {
    if(last==NULL) {
        printf("empty\n");
        return;
    }
    struct node *cur=last->next;
    do {
        printf("%d->", cur->val);
        cur=cur->next;
    }while(cur!=last->next);

    printf("\n");
}

int main() {
    insertFront(12);
    display();
    insertFront(18);
    display();
    insertFront(32);
    display();
    deleteRear();
    display();
    deleteRear();
    display();
    deleteRear();
    display();
    return 0;
}
