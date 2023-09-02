#include <iostream>
using namespace std;

class Queue {
  private:
    int Size;
    int Front=0;
    int Rear=0;
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
    return (Rear+1)%Size==Front;
}
int Queue::isEmpty() {
    return Rear==Front;
}
void Queue::enqueue(int x) {
    if (isFull()) {
        cout<<"Full Queue"<<endl;
    } else {
        Rear=(Rear+1)%Size;
        Q[Rear]=x;
    }
}
int Queue::dequeue() {
    int x=-1;
    if (isEmpty()) {
        cout<<"Empty Queue"<<endl;
    } else {
        x=Q[(Front+1)%Size];
        Front=(Front+1)%Size;
    }
    return x;
}
void Queue::display() {
    int p=Front+1;
    do{
        cout<<Q[p]<<endl;
        p=(p+1)%Size;
    }while(p!=(Rear+1)%Size);
}
int main() {
    Queue* q=new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->dequeue();
    q->dequeue();
    q->enqueue(4);
    q->enqueue(7);
    q->display();

    return 0;
}
