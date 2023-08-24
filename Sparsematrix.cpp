#include <iostream>
using namespace std;

class element{
public:
int i;
int j;
int x;};
class sparse{
private:
int m;
int n;
int num;
element *e;
public:
friend istream & operator>>(istream & is, sparse &s );
void Display(){
    int i,j,k=0;
for (i=0;i<n;i++){
    for (j=0;j<m;j++)
    {
        if (i==e[k].i && j==e[k].j){
            cout<<e[k++].x;
        }
        else {cout<<0;}
    }
    cout<<endl;
}
}
sparse * add (sparse *b){
if (this->m !=b->m || this->n!=b->n){
    return NULL;
}
sparse *sum;
sum=new sparse;
sum->m=this->m;
sum->n=this->n;
sum->e=new element[this->num+b->num];
int i=0,j=0,k=0;
while (i<this->num && j<b->num){
if (this->e[i].i<b->e[j].i){
    sum->e[k++]=this->e[i++];
}
else if(this->e[i].i>b->e[j].i){
sum->e[k++]=b->e[j++];
}
else {
    if (this->e[i].j<b->e[j].j){
        sum->e[k++]=this->e[i++];
    }
    else if (this->e[i].j>b->e[j].j){
       sum->e[k++]=b->e[j++];
    }
    else {sum->e[k]=this->e[i++];
        sum->e[k++].x+=b->e[j++].x;
        }
}
}
for (;i<this->num;i++){
    sum->e[k++]=this->e[i];
}
for (;j<b->num;j++){
    sum->e[k++]=this->e[j];
}
sum->num=k;
return sum;
}

~sparse(){
delete []e;
}
};
istream & operator>>(istream & is, sparse &s ){
cout<<"Enter dimensions & num of non zero elements"<<endl;
is>>s.n>>s.m>>s.num;
s.e=new element [s.num];
cout<<"Enter all non zero elements"<<endl;
for (int i=0;i<s.num;i++){
    is>>s.e[i].i>>s.e[i].j>>s.e[i].x;
}
return is;
}

int main(){
sparse s;
cin>>s;
s.Display();
sparse b;
cin>>b;
b.Display();
cout<<"Result of addition is: "<<endl;
sparse* c = s.add(&b);
c->Display();

return 0;}
