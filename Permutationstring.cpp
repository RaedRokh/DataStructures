#include <iostream>
#include <cstring>
using namespace std;

void permute(char s[], int k){
static int A[10]={0};
static char Res[10];
if (s[k]=='\0'){
    Res[k]='\0';
    cout<<Res<<endl;
}
for (int i=0;s[i]!='\0';i++){
    if (A[i] == 0){
        Res[k]=s[i];
        A[i]=1;
        permute(s,k+1);
        A[i]=0;

    }
}

}
int main(){
char String[]={'a','b','c','\0'};
permute(String,0);
return 0;}
