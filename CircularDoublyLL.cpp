#include <iostream>
using namespace std;

class node {
public:
int data;
node * next=0;
node * prev=0;};


class CDLL{
private:
        node * head;
public:
    CDLL(int A[],int n);
    void Display();
    void Insert(int pos, int key);
    void Delete(int pos);
};

CDLL::CDLL(int A[],int n){
node *p,*last;
head=new node;
head->data=A[0];
last=head;
for (int i=1;i<n;i++){
    p=new node;
    p->data=A[i];
    p->prev=last;
    p->next=last->next;
    last->next=p;
    last=p;
}
last->next=head;
head->prev=last;
}
void CDLL::Display(){
node*p=head;
do {
    cout<<p->data<<endl;
    p=p->next;
}while (p!=head);
}
void CDLL::Insert(int pos,int key){
node *t=new node;
t->data=key;
if (!head){
    t=head;
    head->next=head;
    head->prev=head;
}
if (pos==0){

t->next=head;
t->prev=head->prev;
head->prev=t;
head->prev->next=t;
head=t;
}
else {
node *p=head;
for (int i=0;i<pos-1;i++){
    p=p->next;
}
t->next=p->next;
t->prev=p;
p->next->prev=t;
p->next=t;
}
}
int main(){
int A[]={1,3,5,2,4};
CDLL *m=new CDLL(A,5);
m->Insert(0,0);
m->Display();
return 0;}
