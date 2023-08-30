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

int main(){
int A[]={1,3,5,2,4};
CDLL *m=new CDLL(A,5);
return 0;}
