#include <iostream>
namespace Q{
using namespace std;
class node {
  public:
    node *rchild=0;
    node *lchild=0;
    int data;
};
class Queue {
  private:
    int Size;
    int Front=-1;
    int Rear=-1;
    node **Q;
  public:
    Queue(int s) {
        this->Size=s;
        Q=new node*[s];
    };
    void enqueue(node* x);
    node* dequeue();
    void display();
    int first();
    int last();
    int isFull();
    int isEmpty();
};
int Queue::isFull() {
    return Rear==Size-1;
}
int Queue::isEmpty() {
    return Rear==Front;
}
void Queue::enqueue(node* x) {
    if (isFull()) {
        cout<<"Full Queue"<<endl;
    } else {
        Rear++;
        Q[Rear]=x;
    }
}
node* Queue::dequeue() {
    node* x=0;
    if (isEmpty()) {
        cout<<"Empty Queue"<<endl;
    } else {
        x=Q[Front+1];
        Front++;
    }
    return x;
}
void Queue::display() {
    int p=Front+1;
    for (p; p<=Rear; p++) {
        cout<<Q[p]<<endl;
    }
}
}
