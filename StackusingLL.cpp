#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node * next=0;
};

class Stack {
  private:
    node * top;
  public:
    Stack() {
        top=0;
    }
    void push(int val);
    int pop();
    void display();
    int peek(int pos);
};
void Stack::push(int val) {
    node *t=new node;
    if (!t) {
        cout<<"Stack overflow"<<endl;
    } else {
        t->data=val;
        t->next=top;
        top=t;
    }
}
int Stack::pop() {
    int x=-1;
    if (!top) {
        cout<<"Stack underflow"<<endl;
    } else {
        node *t=top;
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}
void Stack::display() {

    node * p=top;
    while(p) {
        cout<<p->data<<endl;
        p=p->next;
    }
}
int Stack::peek(int pos) {
    if (top && pos>0) {
        node *p=top;
        for (int i=0; i<pos-1 && p; i++) {
            p=p->next;
        }
        return p->data;
    } else {
        return -1;
    }
}

int main() {

Stack* st=new Stack();
st->push(1);
st->push(2);
st->push(3);
cout<<st->peek(1);
    return 0;
}
