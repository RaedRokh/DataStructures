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
void Selectionsort(int A[],int n) {
    for (int i=0; i<n; i++) {
        int k;
        for (int j=k=i; j<n; j++) {
            if (A[j]<A[k]) {
                k=j;
            }
        }
        swap(A[i],A[k]);
    }
}
int Partition(int A[],int l,int h) {
    int pivot=A[l];
    int i=l+1;
    int j=h;
    do {
        do {
            i++;
        } while (A[i]<=pivot);
        do {
            j--;
        } while (A[j]>pivot);
        if (i<j){
        swap(A[i],A[j]);
        }

    } while (i<j);
    swap(A[l],A[j]);
    return j;
}
void Quicksort(int A[],int l,int h){
int j;
if (l<h){
j=Partition(A,l,h);
Quicksort(A,l,j);
Quicksort(A,j+1,h);
}
}
int main() {
    int A[6]= {1,30,6,4,21,INT32_MAX};
    Quicksort(A,0,5);
    for (int i=0; i<5; i++) {
        cout<<A[i]<<endl;
    }



    return 0;
}
