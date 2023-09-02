#include <iostream>
#include <cstring>
#include "StackusingLL.cpp"
using namespace std;
int isOperand(char x) {
    if (x=='+' || x=='-' || x=='/' || x=='*' ||x=='^' ||x=='(' ||x==')' ) {
        return 0;
    } else {
        return 1;
    }
}

int outprecedence(char x) {
    if (x=='+' || x=='-') {
        return 1;
    } else if (x=='*'|| x=='/') {
        return 3;
    } else if (x=='^') {
        return 6;
    } else if (x=='(') {
        return 7;
    } else return 0;

}
int inprecedence(char x) {
    if (x=='+' || x=='-') {
        return 2;
    } else if (x=='*'|| x=='/') {
        return 4;
    } else if (x=='^') {
        return 5;
    } else if (x=='(') {
        return 0;
    } else return 0;

}
char * conversion(char * infix) {
    Stack<char>* st=new Stack<char>;
    char * postfix=new char[strlen(infix)];
    int i=0;
    int j=0;
    while (infix[i]!='\0') {
        if (isOperand(infix[i])) {
            postfix[j++]=infix[i++];

        } else {
            if (infix[i]!=')' || !st->top || outprecedence(infix[i])>inprecedence(st->top->data)) {
                st->push(infix[i++]);
            } else {
                char x=st->pop();
                if (x!='('){postfix[j++]=x;}
                else {i++;}
            }
        }
    }

while (st->top) {
    postfix[j++]=st->pop();
}
postfix[j++]='\0';
return postfix;
}

int main() {
    char *infix = new char[18];

    infix[0] = '(';
    infix[1] = '(';
    infix[2] = 'a';
    infix[3] = '+';
    infix[4] = 'b';
    infix[5] = ')';
    infix[6] = '*';
    infix[7] = 'c';
    infix[8] = ')';
    infix[9] = '-';
    infix[10] = 'd';
    infix[11] = '^';
    infix[12] = 'e';
    infix[13] = '^';
    infix[14] = 'f';
    infix[15] = '\0';
    cout<<conversion(infix);
    return 0;
}

