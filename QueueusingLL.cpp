#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node * next=0;
};

class Queue {
  private:
    node * Front=0;
    node * Rear=0;
  public:
    void enqueue(int val);
    int dequeue();
    void display();
};
void Queue::enqueue(int val) {
    node *t=new node;
    if (!t) {
        cout<<"Full Queue"<<endl;
    } else if (!Front) {
        t->data=val;
        Front=t;
        Rear=t;
    } else {
        t->data=val;
        Rear->next=t;
        Rear=t;
    }
}
int Queue::dequeue() {
    int x=-1;
    if (!Front) {
        cout<<"Empty Queue"<<endl;

    } else {
        node *t=Front;
        x=t->data;
        Front=Front->next;
        delete t;
    }
    return x;
}
void Queue::display() {
    node*p=Front;
    while(p) {
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main() {
    Queue *q=new Queue;
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->dequeue();
    q->display();

    return 0;
}
