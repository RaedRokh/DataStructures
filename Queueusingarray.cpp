#include <iostream>
using namespace std;

class Queue {
  private:
    int Size;
    int Front=-1;
    int Rear=-1;
    int *Q;
  public:
    Queue(int s) {
        this->Size=s;
        Q=new int[s];
    };
    void enqueue(int x);
    int dequeue();
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
void Queue::enqueue(int x) {
    if (isFull()) {
        cout<<"Full Queue"<<endl;
    } else {
        Rear++;
        Q[Rear]=x;
    }
}
int Queue::dequeue() {
    int x=-1;
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
int main() {
    Queue* q=new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->display();

    return 0;
}
