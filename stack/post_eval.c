#include <stdio.h>
#include <ctype.h>
#include <math.h>

int cal(char ch, int op1, int op2) {
    switch (ch)
    {
    case '+': return op1+op2;
    case '-': return op1-op2;
    case '*': return op1*op2;
    case '/': return op1/op2;
    case '^': return pow(op1, op2);
    default: return 0;
    }
}

int postfixEval(char postfix[]) {
    int stack[30], top=-1, op1, op2, res;
    for(int i=0; postfix[i]!='\0'; i++) {
        if(isdigit(postfix[i])) stack[++top]=postfix[i]-'0';
        else {
            op2=stack[top--];
            op1=stack[top--];
            stack[++top]=cal(postfix[i], op1, op2);
        }
    }

    return stack[top--];
}

void main() {
    char post[]="12+3-21+3^-";
    int res=postfixEval(post);

    printf("%d", res);
}