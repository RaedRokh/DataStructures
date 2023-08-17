#include <iostream>

using namespace std;
struct Array {
int *A;
int size;
int length;
void add(int x){
    if (length<size){
    A[length++]=x;
    };
};
void insert(int index, int x){
for (int i=length; i>index ; i--){
A[i+1]=A[i];
};
A[index]=x;
length++;
};
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
    x[1]=1;
    x[2]=1;
    struct Array arr ={x,5,3};
    display(arr);
    arr.insert(1,2);
    arr.add(5);
    display(arr);
    return 0;
}
