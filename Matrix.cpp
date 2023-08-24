#include <iostream>
using namespace std;
class dmatrix{
private:
int *A;
int n;
public:
dmatrix(int n){
this->n=n;
A=new int[n];}
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
~dmatrix(){delete []A;}
};
int main(){
dmatrix m(4);
m.Set(1,1,1);
m.Set(2,2,8);
m.Set(3,3,9);
m.Set(4,4,3);
m.Display();
return 0;
}
