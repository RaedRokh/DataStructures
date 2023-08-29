#include <iostream>
using namespace std;
class node {
public:
node* prev=0;
node* next=0;
int data;};

class DoublyLL{
private:
node* first;
public:
    DoubleLL();
    DoublyLL(int A[],int n);
    void display();
};
DoublyLL::DoublyLL(int A[],int n){

    node *t,*last;
    int i;
    first=new node;
    first->data=A[0];
    first->prev=first->next=0;
    last=first;
    for (i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    };
    }
void DoublyLL::display(){
node *p=first;
while (p!=0){
        cout<<p->data;
        p=p->next;
}
}
int main(){
int A[]={1,3,4,5,7};
DoublyLL *L=new DoublyLL(A,5);
L->display();


return 0;}
