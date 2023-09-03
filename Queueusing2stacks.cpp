#include "Stack.cpp"

void enqueue(Stack *st1,int val) {
    if (!st1->isFull()) {
        st1->push(val);
    }
    else {cout<<"Full Queue"<<endl;}
}
int dequeue(Stack *st1,Stack *st2) {
    int x=-1;
    if (st2->isEmpty()) {
        if (!st1->isEmpty()) {
            while(!st1->isEmpty()) {
                st2->push(st1->pop());
            }
            x=st2->pop();
        }
        else {cout<<"Empty Queue"<<endl;}
    }
    else {x=st2->pop();}
    return x;
}
int main() {
Stack *st1=new Stack(4);
Stack *st2=new Stack(4);
enqueue(st1,0);
enqueue(st1,1);
enqueue(st1,2);
enqueue(st1,3);
enqueue(st1,3);
enqueue(st1,3);
cout<<dequeue(st1,st2)<<endl;
cout<<dequeue(st1,st2)<<endl;
cout<<dequeue(st1,st2)<<endl;
cout<<dequeue(st1,st2)<<endl;
cout<<dequeue(st1,st2)<<endl;

    return 0;
}
