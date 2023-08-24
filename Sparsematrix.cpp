#include <iostream>
using namespace std;

class element{
public:
int i;
int j;
int x;};
class sparse{
private:
int m;
int n;
int num;
element *e;
public:
sparse(){
cout<<"Enter dimensions & num of non zero elements"<<endl;
cin>>n>>m>>num;
e=new element [num];
cout<<"Enter all non zero elements"<<endl;
for (int i=0;i<num;i++){
    cin>>e[i].i>>e[i].j>>e[i].x;
}

}
Display(){
    int i,j,k=0;
for (i=0;i<n;i++){
    for (j=0;j<m;j++)
    {
        if (i==e[k].i && j==e[k].j){
            cout<<e[k++].x;
        }
        else {cout<<0;}
    }
    cout<<endl;
}
}


};

int main(){
sparse s;
s.Display();

return 0;}
