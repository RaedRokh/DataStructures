#include <iostream>
using namespace std;

class Stack {
  private:
    int Size;
    int Top=-1;
    int * st;
  public:
    Stack(int Size) {
        this->Size=Size;
        st=new int[Size];
    }
    void push(int e);
    void display();
    int pop();
    int isEmpty();
    int isFull();
    int Peek(int pos);
    int StackTop();

};
int Stack::isEmpty() {
    return Top==-1;
}
int Stack::isFull() {
    return Top==Size-1;
}
void Stack::push(int e) {
    if (isFull()) {
        cout<<"Stack overflow"<<endl;
    } else {
        Top++;
        st[Top]=e;
    }
}
int Stack::pop() {
    int x=-1;
    if (isEmpty()) {
        cout<<"Stack underflow"<<endl;

    } else {
        x=st[Top];
        Top--;
    }
    return x;
}
int Stack::Peek(int pos) {
    int index=Top-pos+1;
    if (index<0) {
        return -1;
    } else {
        return st[index];
    }
}
void Stack::display() {
    for (int i=0; i<=Top; i++) {
        cout<<st[i]<<endl;
    }
}
int Stack::StackTop() {
    if (isEmpty()) {
        return -1;
    } else {
        return st[Top];
    };
}

