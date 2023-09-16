#include <iostream>
#include "array.cpp"
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
        if (i<j) {
            swap(A[i],A[j]);
        }

    } while (i<j);
    swap(A[l],A[j]);
    return j;
}
void Quicksort(int A[],int l,int h) {
    int j;
    if (l<h) {
        j=Partition(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);
    }
}
void Merge(Array<int> * A,int l,int mid, int h) {
    Array<int> *B=new Array<int>;
    int i=l;
    int j=mid+1;
    int k=l;
    while (i<=mid && j<=h) {

        if (A->A[i]<A->A[j]) {
            B->A[k++]=A->A[i++];
        } else if (A->A[i]>A->A[j]) {
            B->A[k++]=A->A[j++];
        } else {
            B->A[k++]=A->A[j++];
            i++;
        }
    }
    for (; i<=mid; i++) {
        B->A[k++]=A->A[i];
    }
    for (; j<=h; j++) {
        B->A[k++]=A->A[j];
    }
    for (int i=0; i<=h; i++) {
        A->A[i]=B->A[i];
    }
}
int main() {
    Array<int> * A=new Array<int>;
    A->Add(1);
    A->Add(3);
    A->Add(5);
    A->Add(7);
    A->Add(2);
    A->Add(4);
    A->Add(6);
    Merge(A,0,3,6);
    A->Display();



    return 0;
}
