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
    int length();
    void Insert(int pos,int key);
    int Delete(int pos);
    void Reverse();
};
void DoublyLL::Reverse(){
node *p=first;
node *t;
while (p){
    t=p->next;
    p->next=p->prev;
    p->prev=t;
    p=p->prev;
    if (p && !p->next){
    first=p;
}
}

}
int DoublyLL::Delete(int pos){
if (pos<0 || pos>this->length()-1) return -1;
node *p=first;
int x;
if (pos==0){

    first=first->next;
    if (first->next){
        first->next->prev=0;
    }
    x=p->data;
    delete p;
}
else {
    node *q=p;
    for (int i=0;i<pos;i++){
        q=p;
        p=p->next;
    }
    x=p->data;
    q->next=p->next;
    if (p->next){
    p->next->prev=q;}
    delete p;
}
return x;
}
void DoublyLL::Insert(int pos,int key){
if (pos<0 || pos>this->length()-1){
    throw "erro";
}
if (first==0){
    first->data=key;
}
node *t=new node;
t->data=key;
if (pos==0){
    t->prev=0;
    t->next=first;
    first->prev=t;
    first=t;
}
else {
    node *p=first;
    for (int i=0;i<pos-1;i++){
        p=p->next;
    }
    t->next=p->next;
    t->prev=p;
    p->next=t;
    if (p->next){
    p->next->prev=t;}
}
}
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
int DoublyLL::length(){
    node* p=first;
    int i=0;
while (p!=0){
        i++;
        p=p->next;
}
return i;}
int main(){
int A[]={1,3,4,5,7};
DoublyLL *L=new DoublyLL(A,5);
L->Reverse();
L->display();

return 0;}
