#include <iostream>

using namespace std;

class node {
public:
    int val;
    int col;
    node * next=0;
    node(int col,int val)
    {
        this->col=col;
        this->val=val;
    }
};
class sparse {
private:
    int row;
    int col;
    node** matrix;
public:
    sparse(int row,int col)
    {
        this->row=row;
        this->col=col;
        matrix = new node*[row];
    }
    void display();
    void Insert(int row,node * a);
    sparse* add(sparse* b);

};
sparse* sparse::add(sparse* b)
{
    sparse * r=new sparse(this->row,this->col);
    for (int i=0; i<this->row; i++) {
        node *s=0;
        node*p=this->matrix[i];
        node*q=b->matrix[i];
        while(p && q) {
            if (s==0) {
                s=new node(0,0);
                r->matrix[i]=s;
            }
            if (p->col<q->col) {
                s->col=p->col;
                s->val=p->val;
                p=p->next;
            }
            else if (p->col>q->col) {
                s->col=q->col;
                s->val=q->val;
                q=q->next;
            }
            else {
                s->col=q->col;
                s->val=q->val+p->val;
                q=q->next;
                p=p->next;
            }
            if (p || q) {
                s->next=new node(0,0);
                s=s->next;
            }
        }
        while (p) {
            s->next=new node(0,0);
            s->next->val=p->val;
            s->next->col=p->col;
            s=s->next;
            p=p->next;
        }
        while (q) {
            s->next=new node(0,0);
            s->next->val=q->val;
            s->next->col=q->col;
            s=s->next;
            q=q->next;
        }
    }
    return r;
}
void sparse::display()
{
    node *p;
    for (int i=0; i<row; i++) {
        p=matrix[i];
        for (int j=0; j<col; j++) {
            if (p && j==p->col) {
                cout<<p->val;
                p=p->next;
            }
            else cout<<0;
        }
        cout<<endl;
    }
}

void sparse::Insert(int row,node *a)
{
    node *p=matrix[row];
    if (!p) {
        matrix[row]=a;
    }
    else if (a->col==0 || p->col>a->col) {
        a->next=p;
        matrix[row]=a;
    }
    else {
        while (p->next && p->next->col<a->col) {
            p=p->next;
        }
        a->next=p->next;
        p->next=a;
    }

}
int main()
{

    int r,c,col,val,j,x;
    cout<<"Enter number of rows & cols";
    cin>>r>>c;
    sparse *m=new sparse(r,c);
    node *a;
    for (int i=0; i<r; i++) {
        cout<<1+i<<" row"<<endl;
        j=0;
        while (j<c) {
            cout<<"Would you like to insert an element?"<<endl;
            cin>>x;
            if (x==1) {
                cout<<"Enter element's column & value"<<endl;
                cin>>col>>val;
                a=new node(col,val);
                m->Insert(i,a);
                j++;
            }
            else {
                break;
            }
        };
    }
    sparse *n=new sparse(r,c);
    n=m->add(m);
    n->display();
    return 0;
}
