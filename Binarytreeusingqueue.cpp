#include "StackusingLL.cpp"
#include "Queueusingarray.cpp"
using namespace Q;
class tree {

public:
    Q::node *root;
    tree()
    {
        root=new Q::node;
    }
    void create();
    void preorder(Q::node* p);
    void postorder(Q::node* p);
    void inorder(Q::node* p);
    void levelorder();
    int height(Q::node* root);
    void preorderit(Q::node *p);
    void inorderit(Q::node*p);
    void postorderit(Q::node*p);
    int countnodes(Q::node * p);
    int countleafs(Q::node * p);
};
void tree::create()
{
    Queue *q=new Q::Queue(100);
    int val;
    cout<<"Enter root value: "<<endl;
    cin>>val;
    root->data=val;

    q->enqueue(root);
    node *p=root;
    node *t;
    while(!q->isEmpty()) {
        p=q->dequeue();

        cout<<"Enter L child value of "<<p->data<<" "<<endl;
        cin>>val;
        if (val!=-1) {
            t=new node;
            t->data=val;
            p->lchild=t;
            q->enqueue(t);

        }
        cout<<"Enter R child value of "<<p->data<<" "<<endl;
        cin>>val;
        if (val!=-1) {

            t=new node;
            t->data=val;
            p->rchild=t;
            q->enqueue(t);
        }

    }

}

void tree::preorder(node* p)
{
    if (p) {
        cout<<p->data<<endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::postorder(node* p)
{
    if (p) {


        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<endl;
    }
}
void tree::inorder(node* p)
{
    if (p) {
        inorder(p->lchild);
        cout<<p->data<<endl;
        inorder(p->rchild);
    }
}
void tree::levelorder()
{
    Queue *q=new Queue(100);
    node *p=root;
    q->enqueue(p);
    cout<<p->data<<endl;
    while(!q->isEmpty()) {
        p=q->dequeue();
        if (p->lchild) {
            cout<<p->lchild->data<<endl;
            q->enqueue(p->lchild);
        }
        if (p->rchild) {
            cout<<p->rchild->data<<endl;
            q->enqueue(p->rchild);
        }

    }
}
int tree::height(node* root)
{
    if (!root) {
        return 0;
    }
    return max(root->lchild?1+height(root->rchild):0,root->lchild?1+height(root->lchild):0);
}

void tree::preorderit(node*p)
{
    S::Stack<node*> *s=new S::Stack<node*>();
    while (s->top || p) {
        if (p) {
            s->push(p);
            cout<<p->data<<endl;
            p=p->lchild;

        }
        else {
            p=s->pop();
            p=p->rchild;
        }
    }
}
void tree::inorderit(node*p)
{
    S::Stack<node*> *s=new S::Stack<node*>();
    while (s->top || p) {
        if (p) {
            s->push(p);
            p=p->lchild;

        }
        else {
            p=s->pop();
            cout<<p->data<<endl;
            p=p->rchild;
        }
    }
}
void tree::postorderit(Q::node*p)
{
    node * t=p;
    S::Stack<node*> *s=new S::Stack<node*>();
    while(t || s->top) {
        if (t) {
            s->push(t);
            t=t->lchild;
        }
        else {
            t=s->pop();
            intptr_t address = reinterpret_cast<intptr_t>(t);
            if (address>0) {
                address = -address;
                s->push(reinterpret_cast<node*>(address));
                t=t->rchild;
            }
            else {
                t = reinterpret_cast<node*>(-address);
                cout<<t->data<<endl;
                t=nullptr;
            }
        }
    }
}
int tree::countnodes(node * p){
    int x,y;
if (p){
x=countnodes(p->lchild);
y=countnodes(p->lchild);
return x+y+1;
}
return 0;
}
int tree::countleafs(node * p){
    int x,y;
if (p){
x=countnodes(p->lchild);
y=countnodes(p->lchild);
if (!p->lchild || !p->rchild){
return x+y+1;}
else {return x+y;}
}
return 0;

}
int main()
{
    tree* t=new tree;
    t->create();
    cout<<t->countleafs(t->root)<<endl;
    return 0;
}
