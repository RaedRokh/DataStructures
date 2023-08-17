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
int Lsearch(int key){
    for (int i=0; i<length ; i++){
        if (A[i]== key){
            swap(A[i],A[0]);
            return i;
        }
    }
    return -1;
};
int Bsearch(int key){
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
int Get(int index){
    if (index <= length && index >=0){
        return A[index];
    }
    return -1;
}
void Set(int index, int key){
    if (index <= length && index >=0){
        A[index]=key;
    }
}
int Max(){
    int Max=A[0];
    for (int i=1; i< length ; i++){
        if (A[i]>Max){
            Max=A[i];
        }
    }
    return Max;
}
int Min(){
    int Min=A[0];
    for (int i=1; i< length ; i++){
        if (A[i]<Min){
            Min=A[i];
        }
    }
    return Min;
}
void Reverse(){
    int temp,i,j;
for (i=0,j=length-1;i<j; i++,j--){
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
};
    };
void Sinsert(int key){
int i=length-1;
while (A[i]>key){
A[i+1]=A[i];
i--;}
A[i+1]=key;
length++;
}
bool isSorted(){
    int i;
    for (i=0;i<length-1;i++){
        if (A[i]>A[i+1]){
            return false;
        }
    }
    return true;
};
void seperatesign(){
    int i=0,j=length-1;
    while(i<j){
        while(A[i]<0){i++;};
        while(A[j]>=0){j--;};
        if (i<j){
        swap(A[i],A[j]);}
    };
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
    int *x=new int[4];
    x[0]=-3;
    x[1]=2;
    x[2]=-3;
    x[3]=3;
    struct Array arr ={x,5,4};
    arr.seperatesign();
    display(arr);
    return 0;
}
