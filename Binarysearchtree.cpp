#include "Binarytreeusingqueue.cpp"
using namespace Q;

class bst:public tree {
  public:
    void IInsert(int key);
    node * RInsert(node * p,int key);
    Q::node* Rsearch(Q::node* p,int key);
};
Q::node* bst::Rsearch(Q::node* p,int key) {
    if (!p) {
        return 0;
    }
    if (p->data==key) {
        return p;
    } else if (p->data>key) {
        return Rsearch(p->lchild,key);
    } else {
        return Rsearch(p->rchild,key);
    }
}
node * bst::RInsert(node * p,int key) {

    if (!p) {
        node *t =new node;
        t->data=key;
       return t;
    }
    if (p->data==key) {
        return p;
    } else if (p->data>key) {
        p->lchild=RInsert(p->lchild,key);
    } else {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}
void bst::IInsert(int key) {
    node * t=root;
    node * r=root;
    node * p=new node();
    p->data=key;
    p->rchild=0;
    p->lchild=0;
    if (!root) {
        root=p;
        return;
    }
    while (t) {
        r=t;
        if (key<t->data) {
            t=t->lchild;

        } else if (key>t->data) {
            t=t->rchild;
        } else {
            return;
        }
    }
    if (key<r->data) {
        r->lchild=p;
    } else {
        r->rchild=p;
    }
}
int main() {
    bst * t=new bst;
    t->root=new node;
    t->root=t->RInsert(t->root,10);
    t->RInsert(t->root,5);
    t->RInsert(t->root,30);
    t->inorderit(t->root);
    if (t->Rsearch(t->root,40)) {
        cout<<"found"<<endl;
    } else {
        cout<<"unfound"<<endl;
    }

    return 0;
}
