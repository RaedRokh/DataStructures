#include <iostream>
using namespace std;
namespace S{
template <class T>
class node {
  public:
    T data;
    node * next=0;
};
template <class T>
class Stack {

  public:
    node<T> * top;
    Stack() {
        top=0;
    }
    void push(T val);
    T pop();
    void display();
    T peek(int pos);
};
template <class T>
void Stack<T>::push(T val) {
    node<T> *t=new node<T>;
    if (!t) {
        cout<<"Stack overflow"<<endl;
    } else {
        t->data=val;
        t->next=top;
        top=t;
    }
}
template <class T>
T Stack<T>::pop() {
    T x=(T)-1;
    if (!top) {
        cout<<"Stack underflow"<<endl;
    } else {
        node<T> *t=top;
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}
template <class T>
void Stack<T>::display() {

    node<T> * p=top;
    while(p) {
        cout<<p->data<<endl;
        p=p->next;
    }
}
template <class T>
T Stack<T>::peek(int pos) {
    T x=-1;
    if (top && pos>0) {
        node<T> *p=top;
        for (int i=0; i<pos-1 && p; i++) {
            p=p->next;
        }
        x=p->data;
    } else {
        cout<<"Invalid index"<<endl;
    }
    return x;
}
}
//int main() {
//
//    return 0;
//}
