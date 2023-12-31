#include <iostream>
using namespace std;
template <class T>
class Array {
    private:
T *A;
int Size;
int length;
    public:
        Array(){
        Size=10;
        length=0;
        A=new T[Size];}
        Array(int s){
            Size=s;
            length=0;
        A=new T[Size];
        }
        ~Array(){
        delete []A;}
void Add(T x){
    if (length<Size){
    A[length++]=x;
    };
};
void Insert(int index, T x){
    cout<<length;
if (index>=0 && index<=length){
for (int i=length; i>index ; i--){
A[i]=A[i-1];
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
int Lsearch(T key){
    for (int i=0; i<length ; i++){
        if (A[i]== key){
            swap(A[i],A[0]);
            return i;
        }
    }
    return -1;
};
int Bsearch(T key){
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
T Get(int index){
    if (index <= length && index >=0){
        return A[index];
    }
    return -1;
}
void Set(int index, T key){
    if (index <= length && index >=0){
        A[index]=key;
    }
}
T Max(){
    T Max=A[0];
    for (int i=1; i< length ; i++){
        if (A[i]>Max){
            Max=A[i];
        }
    }
    return Max;
}
T Min(){
    T Min=A[0];
    for (int i=1; i< length ; i++){
        if (A[i]<Min){
            Min=A[i];
        }
    }
    return Min;
}
void Reverse(){
    int i,j;
    T temp;
for (i=0,j=length-1;i<j; i++,j--){
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
};
    };
void Sinsert(T key){
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
void Display(){
int i;
cout<<"elements are:"<<endl;
for(i=0; i<length ; i++){
    cout<<A[i]<<endl;
};
};
 Array *Merge(Array *b){
int i=0,j=0,k=0;
Array *c=new Array;
c->length=this->length+b->length;
c->Size=this->Size+b->Size;
    while(i<this->length && j<b->length){
        if (this->A[i]>b->A[j]){
                c->A[k++]=b->A[j++];
            }
            else if(this->A[i]<b->A[j]) {
                 c->A[k++]=this->A[i++];
            }
            else {
                c->A[k++]=this->A[i++];
                }
        }
        for(;j<b->length;j++){
            c->A[k++]=b->A[j];
        }
          for(;i<this->length;i++){
            c->A[k++]=this->A[i];
        }
    return c;
}
Array *findmissingsorted(){
Array *brr=new Array;
int distance=this->A[0];
int i;
for (i=1;i<this->length;i++){
    while(this->A[i]-i>distance){
        brr->Add(distance+i);
        distance++;
    }

}
return brr;
}
void findmissingunsorted(){

Array *brr=new Array(this->Max());
for (int i = 0; i < brr->Size; i++) {
    brr->Add(0);
}
int i;
for (i=0; i<this->length; i++){
    brr->A[this->A[i]]++;
}
for (i=this->Min();i<brr->length;i++){
    if (brr->A[i]==0){
        cout<<i<<endl;
    }
}
}
void findduplicatesorted(){
int dup=0;
int j;
for (int i=0;i<this->length-1;i++){
    if (this->A[i]==this->A[i+1]){
        dup=this->A[i];
        j=i+1;
        while(A[j]==A[i]){
            j++;
        }
        cout<<dup<<" is a duplicate element with "<<j-i<<" duplicates"<<endl;
        i=j-1;
    }}
}
void findduplicateunsorted(){
Array * brr=new Array(this->Max()+1);
int i;
for (i=0;i<=brr->Size;i++){
    brr->Add(0);
}

for (i=0;i<this->length;i++){
    brr->A[this->A[i]]++;
}
for (i=this->Min();i<brr->Size;i++){
    if (brr->A[i]>1){
        cout<<i<<" is a duplicate element with"<<brr->A[i]<< " duplicates"<<endl;
    }
}
}
void findpairunsorted(int n){
Array * brr=new Array(this->Max()+1);
int i;
for (i=0;i<brr->Size;i++){
    brr->Add(n);
}

for (i=0;i<this->length;i++){

    brr->A[this->A[i]]-=this->A[i];
}
for (i=this->Min();i<brr->Size;i++){
    if (brr->A[i]+brr->A[brr->A[i]]==n){
        cout<<"pairs are: ("<<brr->A[i]<<","<<brr->A[brr->A[i]]<<")"<<endl;
    }
}
}
void findpairsorted(int n){
int i=0,j=this->length-1;
while(i<j){
    if (this->A[i]+this->A[j]==n){
        cout<<"pairs are: ("<<this->A[i]<<","<<this->A[j]<<")"<<endl;
        i++;
        j--;
    }
    else if(this->A[i]+this->A[j]>n){
        j--;
    }
    else {i++;}
    }
}
};




int main()
{
   Array<int> *arr1;
 int ch,sz;
int index;
int x;

 cout<<"Enter Size of Array";
 cin>>sz;
 arr1=new Array<int>(sz);

 do
 {
    cout<<"\n\nMenu\n";
    cout<<"1. Add\n";
    cout<<"2. Delete\n";
    cout<<"3. Search\n";
    cout<<"4. Reverse\n";
    cout<<"5. Insert\n";
    cout<<"6. Find missing elements sorted\n";
    cout<<"7. Find missing elements unsorted\n";
    cout<<"8. Display\n";
    cout<<"9.Count duplicate elements sorted\n";
    cout<<"10.Count duplicate elements unsorted\n";
     cout<<"11.Find pair for sum unsorted\n";
      cout<<"12.Find pair for sum sorted\n";
    cout<<"13.Exit\n";

 cout<<"enter you choice ";
 cin>>ch;

 switch(ch)
 {
 case 1: cout<<"Enter an element" ;
 cin.ignore();
 cin>>x;
 arr1->Add(x);
 break;
 case 2: cout<<"Enter index ";
 cin>>index;
 arr1->Delete(index);
 cout<<"Deleted Element is"<<x;
 break;
 case 3:cout<<"Enter element to search";
 cin.ignore();
 cin>>x;
 index=arr1->Lsearch(x);
 cout<<"Element index "<<index;
 break;
 case 4:
     arr1->Reverse();
     cout<<"Reversed";
     arr1->Display();
 break;
 case 5: cout<<"Enter element & index"<<endl;
 int el,in;
 cin.ignore();
 cin>>el>>in;
 arr1->Insert(in,el);
 break;
 case 6:{
     Array<int >* brr=new Array<int>;
    brr=arr1->findmissingsorted();
    brr->Display();
 break;}
  case 7:
    arr1->findmissingunsorted();
    break;
 case 8:
    arr1->Display();
 break;
 case 9:
    arr1->findduplicatesorted();
    break;
    case 10:
        arr1->findduplicateunsorted();
        break;
    case 11:
        cout<<"Enter sum"<<endl;
        cin.ignore();
        cin>>in;
        arr1->findpairunsorted(in);
        break;
     case 12:
    cout<<"Enter sum"<<endl;
    cin.ignore();
    cin>>in;
    arr1->findpairsorted(in);
    break;
 }
 }while(ch<13);
    return 0;
}
