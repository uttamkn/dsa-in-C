#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *right;
    struct node *left;
};
struct node *root=NULL;

struct node* insertBST(struct node *root, int item) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=item;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL) return temp;
    struct node *cur=root, *prev=NULL;
    while(cur!=NULL) {
        prev=cur;
        if(item<cur->val) cur=cur->left;
        else cur=cur->right;
    }
    if(item<prev->val) prev->left=temp;
    else prev->right=temp;

    return root;
}

void inorder(struct node *root) {
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void searchBST(struct node *root, int item) {
    if(root==NULL) {
        printf("empty");
        return;
    }
    struct node *cur=root;
    while(cur!=NULL) {
        if(cur->val==item) {
            printf("found\n");
            return;
        }
        if(item<cur->val) cur=cur->left;
        else cur=cur->right;
    }

    printf("Not found\n");
}

void highest(struct node *root) {
    if(root==NULL) {
        printf("empty");
        return;
    }

    struct node *cur=root;
    while(cur->right!=NULL) {
        cur=cur->right;
    }

    printf("\nHighest: %d", cur->val);
}

void lowest(struct node *root) {
    if(root==NULL) {
        printf("empty");
        return;
    }

    struct node *cur=root;
    while(cur->left!=NULL) {
        cur=cur->left;
    }

    printf("\nLowest: %d\n", cur->val);
}

void main() {
    int marks, numOfStus=6;
    for(int i=0; i<numOfStus; i++) {
        printf("Enter marks of student %d: ", i+1);
        scanf("%d", &marks);
        root=insertBST(root, marks);
    }
    printf("\n========Marks in order==========\n");
    inorder(root);
    highest(root);
    lowest(root);
    int mark;
    printf("Enter the mark that is to be searched: ");
    scanf("%d", &mark);
    searchBST(root, mark);
}