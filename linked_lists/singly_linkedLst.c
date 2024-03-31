#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head=NULL;

void insertFront(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->next=head;
    head=temp;
}

void insertRear(int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
        return;
    }
    struct node *cur=head;
    while(cur->next!=NULL) {
        cur=cur->next;
    }
    cur->next=temp;
}

void insertAtPos(int pos, int item) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->next=NULL;
    if(pos==1) {
        temp->next=head;
        head=temp;
        return;
    }
    int cur_pos=1;
    struct node *cur=head, *prev=NULL;
    while(cur!=NULL) {
        if(cur_pos==pos) break;
        prev=cur;
        cur=cur->next;
        cur_pos++;
    }

    if(cur==NULL && cur_pos!=pos) {
        printf("position not found\n");
        return;
    }

    prev->next=temp;
    temp->next=cur;
}

void deleteFront() {
    if(head==NULL) {
        printf("empty");
        return;
    }
    struct node *temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
}

void deleteItem(int item) {
    if(head==NULL) {
        printf("Empty\n");
        return;
    }
    struct node *prev=NULL, *cur=head;
    while(cur!=NULL) {
        if(cur->val==item) break;
        prev=cur;
        cur=cur->next;
    }

    if(cur==NULL) {
        printf("Item not found\n");
        return;
    }

    if(cur==head) {
        head=head->next;
        free(cur);
        return;
    }
    prev->next=cur->next;
    free(cur);
}

void deleteRear() {
    if(head==NULL) {
        printf("Empty\n");
        return;
    }

    if(head->next==NULL) {
        free(head);
        head=NULL;
        return;
    }

    struct node *cur=head, *prev=NULL;

    while(cur->next!=NULL) {
        prev=cur;
        cur=cur->next;
    }

    prev->next=NULL;
    free(cur);
}

void display() {
    if(head==NULL) {
        printf("Empty\n");
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
    int item, choice, pos;
    for(;;) {
        printf("1. Insert Front\n2. Delete Item\n3. Insert at position\n4. Delete Rear\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Item to be inserted: ");
                scanf("%d", &item);
                insertFront(item);
            }
            break;

            case 2: {
                printf("Item to be deleted: ");
                scanf("%d", &item);
                deleteItem(item);
            }
            break;

            case 3: {
                printf("Item to be inserted: ");
                scanf("%d", &item);
                printf("position: ");
                scanf("%d", &pos);
                insertAtPos(pos, item);
            }
            break;

            case 4: deleteRear();
            break;

            case 5: display();
            break;

            default: return;
        }

    }
}