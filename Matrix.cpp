#include <iostream>
using namespace std;
class Matrix {
    protected:
int *A;
int n;
    public:
        Matrix(int n){this->n=n;
A=new int[n];}
virtual void Set(int i, int j, int x)=0;
virtual int Get(int i, int j)=0;
virtual void Display()=0;};

class Diagonal: public Matrix{

public:
Diagonal(int n):Matrix(n){}
void Set (int i, int j, int x){
if (i==j){
    A[i-1]=x;
    }
}
int Get(int i, int j){
if (i==j){
    return A[i-1];
}
else { return 0;}}
void Display(){
int i,j;
for (i=1;i<=n;i++){
    for (j=1;j<=n;j++){
        if (i==j){
            cout<<A[i-1];
        }
        else {cout<<0;}
    }
    cout<<endl;
}
}
~Diagonal(){delete []A;}
};
class Ltriangle: public Matrix{
public:
    Ltriangle(int n):Matrix(n){};
    void Set(int i, int j,int x){
    if (i>=j){
        A[i*(i-1)/2+j-1]=x;
    }
};
int Get(int i, int j){
if (i>=j){
    return A[i*(i-1)/2+j-1];
}else return 0;}
void Display(){
int i,j;
for (i=1; i<=n;i++){
    for (j=1;j<=n;j++){
        if (i>=j){
            cout<<A[i*(i-1)/2+j-1];
        }
        else cout<<0;
    }
    cout<<endl;
}}
};
int main(){
Ltriangle m(3);
int x,i,j;
for (i=1;i<=3;i++){
    for (j=1;j<=3;j++){
        cin>>x;
        m.Set(i,j,x);
    }
}
m.Display();
return 0;
}
