#include <iostream>

using namespace std;

class node{
    public:
    int val;
    int col;
    node * next=0;
    node(int col,int val){
    this->col=col;
    this->val=val;}
};
class sparse{
    private:
int row;
int col;
node** matrix;
    public:
    sparse(int row,int col){
    this->row=row;
    this->col=col;
    matrix = new node*[row];
}
      void display();
        void Insert(int row,node * a);
        sparse* add(sparse* b);

};
sparse* sparse::add(sparse* b){
    sparse * r=new sparse(this->row,this->col);

    for (int i=0;i<this->row;i++){
        node *s=r->matrix[i];
        node *temp=new node(0,0);
        node*p=this->matrix[i],*q=b->matrix[i];
    while(p && q){
            if (p->col<q->col){
                temp=p;
                p=p->next;
            }
            else if (p->col>q->col){
                 temp=q;
                q=p->next;
            }
            else {temp=q;
            temp->val+=p->val;
            q=q->next;
            p=p->next;}
    }
    while (p){
        temp=p;
        p=p->next;
    }
        while (q){
        temp=q;
        q=q->next;
    }
        s->next=temp;
        s=s->next;
    }
    return r;
}
void sparse::display(){
node *p;
for (int i=0;i<row;i++){
        p=matrix[i];
        for (int j=0;j<col;j++){
            if (p && j==p->col){
            cout<<p->val;
            p=p->next;}
            else cout<<0;
        }
        cout<<endl;
}
}

void sparse::Insert(int row,node *a){
    node *p=matrix[row];
    if (!p){
        matrix[row]=a;
    }
    else if (a->col==0 || p->col>a->col){
        a->next=p;
        matrix[row]=a;
    }
    else {
    while (p->next && p->next->col<a->col){
        p=p->next;
        }
        a->next=p->next;
        p->next=a;}

}
int main(){

int r,c,col,val,j,x;
cout<<"Enter number of rows & cols";
cin>>r>>c;
sparse *m=new sparse(r,c);
node *a;
for (int i=0;i<r;i++){
    cout<<1+i<<" row"<<endl;
    j=0;
    while (j<c){
        cout<<"Would you like to insert an element?"<<endl;
        cin>>x;
        if (x==1){
        cout<<"Enter element's column & value"<<endl;
        cin>>col>>val;
        a=new node(col,val);
        m->Insert(i,a);
        j++;}
        else {break;}
    };
}
m->display();
sparse *n=new sparse(r,c);
n=m->add(m);
n->display();
return 0;}
