#include <iostream>
#include <cstring>
#include "StackusingLL.cpp"
using namespace std;
int isOperand(char x) {
    if (x=='+' || x=='-' || x=='/' || x=='*') {
        return 0;
    } else {
        return 1;
    }
}

int precedence(char x) {
    if (x=='+' || x=='-') {
        return 1;
    } else if (x=='*'|| x=='/') {
        return 2;
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
            if (!st->top || precedence(infix[i])>precedence(st->top->data)) {
                st->push(infix[i++]);
            } else {
                postfix[j++]=st->pop();
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
 char *infix = new char[10];

    infix[0] = 'a';
    infix[1] = '+';
    infix[2] = 'b';
    infix[3] = '+';
    infix[4] = 'c';
    infix[5] = '*';
    infix[6] = 'd';
    infix[7] = '\0';
cout<<conversion(infix);
    return 0;
}

