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
void permute2(char s[], int l, int h){
    int i;
    if (l==h){
    cout<<s<<endl;
}
else {
for (i=l; i<=h;i++){
swap(s[l],s[i]);
permute2(s,l+1,h);
swap(s[l],s[i]);
}
}

}
int main(){
char String[]={'a','b','c','\0'};
permute2(String,0,2);
return 0;}
