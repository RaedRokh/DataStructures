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
int main() {
    int A[5]={1,3,6,20,21};
    Bubblesort(A,5);
    for (int i=0;i<5;i++){
        cout<<A[i]<<endl;
    }



    return 0;
}
