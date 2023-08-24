#include <iostream>
using namespace std;
struct matrix{

int A[10];
int n;
void Set (int i, int j, int x){
if (i==j){
    A[i-1]=x;
    }
}
int Get(int i, int j, int x){
if (i==j){
    return A[i-1];
}
else { return 0;}}
void Display(){
int i,j;
for (i=0;i<n;i++){
    for (j=0;j<n;j++){
        if (i==j){
            cout<<A[i-1]<<endl;
        }
        else {cout<<0<<endl;}
    }
}
}};
int main(){
matrix m;
m.n=4;
m.Set(1,1,5);
m.Set(2,2,8);
m.Set(3,3,9);
m.Set(4,4,10);
m.Display();
return 0;
}
