#include <iostream>

using namespace std;
struct Array {
int *A;
int size;
int length;
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
    struct Array arr;
    int n,i;
    cout<<"enter size of an array"<<endl;
    cin>>arr.size;
    arr.A=new int[arr.size];
    arr.length=0;

    cout<<"enter how many numbers"<<endl;
    cin>>n;
    cout<<"enter all elements"<<endl;
    for (i=0 ; i < n ; i ++){
        cin>>arr.A[i];
    }
    arr.length=n;
    display(arr);
    return 0;
}
