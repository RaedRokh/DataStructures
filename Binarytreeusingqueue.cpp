#include "Queueusingarray.cpp"
class tree {

public:
    node *root;
    tree()
    {
        root=new node;
    }
    void create();
    void preorder(node* p);
    void postorder(node* p);
    void inorder(node* p);
    void levelorder();
    int height(node* root);
};
void tree::create()
{
    Queue *q=new Queue(100);
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
int main()
{
    tree* t=new tree;
    t->create();
    cout<<t->height(t->root);
    return 0;
}
