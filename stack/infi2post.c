#include <stdio.h>
#include <ctype.h>

void infi2post(char infix[], char postfix[]);
int precedence1(char ch);
int precedence2(char ch);

void main() {
    char infix[30] = "p+q*r-(s+t^u)", postfix[30];
    infi2post(infix, postfix);
    puts(postfix);
}

void infi2post(char infix[], char postfix[]) {
    int stack[30], top=-1, k=0;
    char ch;
    for(int i=0; infix[i]!='\0'; i++) {
        ch=infix[i];

        if(isalnum(ch)) {
            postfix[k++]=ch;
        }
        else if(ch == '(') {
            stack[++top] = ch;
        }
        else if(ch==')') {
            while(stack[top]!='(') {
                postfix[k++]=stack[top--];
            }
            top--;
        }
        else {
            while(precedence1(ch)<=precedence2(stack[top])) {
                postfix[k++] = stack[top--];
            }
            stack[++top]=ch;
        }
    }

    while(top!=-1) {
        postfix[k++]=stack[top--];
    }

    postfix[k]='\0';
}

int precedence2(char ch) {
    switch(ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '-':
        case '+': return 1;
        default: return -1;
    }
}

int precedence1(char ch) {
    switch(ch) {
        case '^': return 4;
        case '*':
        case '/': return 2;
        case '-':
        case '+': return 1;
        default: return -1;
    }
}
