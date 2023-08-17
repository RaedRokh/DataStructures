#include <iostream>
using namespace std;
struct Array {
int *A;
int size;
int length;
void Add(int x){
    if (length<size){
    A[length++]=x;
    };
};
void Insert(int index, int x){
if (index>=0 && index<length){
for (int i=length; i>index ; i--){
A[i+1]=A[i];
};
A[index]=x;
length++;
}};
void Delete(int index){
if (index>=0 && index<length){
    for (int i=index; i<length-1; i++){
        A[i]=A[i+1];
    };
    length--;
};
};
int lsearch(int key){
    for (int i=0; i<length ; i++){
        if (A[i]== key){
            swap(A[i],A[0]);
            return i;
        }
    }
    return -1;
};
int bsearch(int key){
    int high=length-1;
    int low=0;
    int mid;
    while (high>=low){
        mid=(low+high)/2;
        if (key<A[mid]){
            high=mid-1;
        }
        else if (key > A[mid]){
            low=mid+1;
        }
        else{
            return mid;}

    }
    return -1;
}
};

void display(struct Array arr){
int i;
cout<<"elements are:"<<endl;
for(i=0; i<arr.length ; i++){
    cout<<arr.A[i]<<endl;
};
}


int main()
{
    int *x=new int[3];
    x[0]=1;
    x[1]=2;
    x[2]=3;
    struct Array arr ={x,4,5};
    cout<<arr.bsearch(2);
    return 0;
}
