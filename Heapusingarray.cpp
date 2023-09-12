#include <iostream>
using namespace std;



void Insert(int A[],int n){
int i=n;
int temp=A[i];
while(i>1 && temp>A[i/2]){
    A[i]=A[i/2];
    i=i/2;
}
A[i]=temp;
}
int main(){
int A[10];
A[0]=0;
A[1]=1;
A[2]=4;
A[3]=5;
A[4]=3;

Insert(A,4);
cout<<A[1]<<endl;


return 0;
}
