#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
struct node *last=NULL;

void insertRear(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->value=item;
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

void display() {
    if(last==NULL) {
        printf("empty\n");
        return;
    }

    struct node *racer=last->next;

    do {
        printf("%d-->", racer->value);
        racer=racer->next;
    }while(racer!=last->next);
    printf("\n");
}

int main() {
    insertRear(12);
    display();
    insertRear(14);
    display();
    insertRear(15);
    display();
    insertRear(18);
    display();
    insertRear(32);
    display();

    return 0;
}
