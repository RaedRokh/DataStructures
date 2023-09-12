#include <iostream>
using namespace std;



void Insert(int A[],int n) {
    int i=n;
    int temp=A[i];
    while(i>1 && temp>A[i/2]) {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int Delete(int A[],int n) {
    int i,j,x;
    x=A[1];
    A[1]=A[n];
    i=1;
    j=i*2;
    while (j<n-1) {
        if (A[j]<A[j+1]) {
            j++;
        }
        if (A[i]<A[j]) {
            swap(A[i],A[j]);
            i=j;
            j=2*j;
        }
        else {break;}

    }
    A[n]=x;
    return x;
}



int main() {
    int A[10];
    A[0]=0;
    A[1]=1;
    A[2]=4;
    A[3]=5;
    A[4]=2;
    A[5]=20;
    for (int i=2; i<=5; i++) {
        Insert(A,i);
    }
  for (int i=1; i<=5; i++) {
        cout<<A[i]<<endl;
    }
    cout<<endl;

    Delete(A,5);
        for (int i=1; i<=5; i++) {
        cout<<A[i]<<endl;
    }

    return 0;
}
