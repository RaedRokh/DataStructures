#include <iostream>
using namespace std;


void Bubblesort(int A[],int n) {
    int flag;
    for (int i=0; i<n; i++) {
        flag=0;
        for (int j=0; j<n-1-i; j++) {
            if(A[j]>A[j+1]) {
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if (flag==0) {
            break;
        }
    }
}
void Insertionsort(int A[],int n) {
    for (int i=1; i<n; i++) {
        int x=A[i];
        int j=i-1;
        while (j>-1 &&x<A[j]) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }

}
void Selectionsort(int A[],int n){
for (int i=0;i<n;i++){
        int k;
    for (int j=k=i;j<n;j++){
        if (A[j]<A[k]){
            k=j;
        }

    }
    swap(A[i],A[k]);
}
}
int main() {
    int A[5]= {1,30,6,4,21};
    Bubblesort(A,5);
    for (int i=0; i<5; i++) {
        cout<<A[i]<<endl;
    }



    return 0;
}
