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


void rdisplay(node *p){
if (p!=0){
    cout<<p->data<<endl;
    rdisplay(p->next);
}

}
int Count(node *p){
if (p==0){
    return 0;
}
return 1+Count(p->next);
}
int sum(node *p){
int s=0;
while (p){
    s+=p->data;
    p=p->next;
}
return s;}
int Max(int currentmax,node *currentnode){
if (currentnode->next==0){
    return currentmax;
}
return currentnode->data>currentmax?Max(currentnode->data,currentnode->next):Max(currentmax,currentnode->next);

}
node * Search(node *p, int key){
if (p==0){
    return nullptr;
}
if (p->data==key){
    return p;
}
Search(p->next,key);
}
int main(){
int A[]={-200,-50,-3,-20,-4};
create(A,5);
//display(first);
rdisplay(first);
cout<<"LL's length is: "<<Count(first)<<endl;
cout<<"LL's sum is: "<<sum(first)<<endl;
cout<<Max(INT_MIN,first)<<endl;
cout<<Search(first,10)->data;
return 0;}


