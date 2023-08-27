#include <iostream>

using namespace std;


class node{
    public:
    int data;
    node *next;};
node *first=0;
void create(int A[],int n){

int i;
node *t,*last;
first=new node;
first->data=A[0];
first->next=0;
last=first;
for (i=1;i<n;i++){
t=new node;
t->data=A[i];
t->next=0;
last->next=t;
last=t;}}

void display(node *p){
while (p!=0){
    cout<<p->data<<endl;
    p=p->next;

}}


void displayr(node *p){
if (p!=0){
 cout<<p->data<<endl;
 displayr(p->next);
}

}




int main(){
int A[]={1,2,3,5,4};
create(A,5);
//display(first);
displayr(first);
return 0;}
