#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};
struct node *head;

void insertRear(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL) {
        head=temp;
        return;
    }
    struct node *cur=head;
    while(cur->next!=NULL) cur=cur->next;
    temp->prev=cur;
    cur->next=temp;
}

void deleteFront() {
    if(head==NULL) {
        printf("empty\n");
        return;
    }
    if(head->next==NULL) {
        free(head);
        head=NULL;
        return;
    }
    head=head->next;
    free(head->prev);
    head->prev=NULL;
}

void display() {
    if(head==NULL) {
        printf("empty\n");
        return;
    }
    struct node *cur=head;
    while(cur!=NULL) {
        printf("%d->", cur->val);
        cur=cur->next;
    }
    printf("NULL\n");
}

void main() {
    insertRear(12);
    display();
    insertRear(13);
    display();
    insertRear(14);
    display();
    deleteFront();
    display();
    deleteFront();
    display();
    deleteFront();
    display();
}