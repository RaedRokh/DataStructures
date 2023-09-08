#include "Binarytreeusingqueue.cpp"
using namespace Q;

class bst:public tree {
  public:
    void IInsert(int key);
    node * RInsert(node * p,int key);
    Q::node* Rsearch(Q::node* p,int key);
    node * Delete(node*p,int key);
};
node * inpre(node * p) {
    while (p && p->rchild) {
        p=p->rchild;
    }
    cout<<p->data<<"eeeeeeee"<<endl;
    return p;
}
node * insucc(node * p) {
    while (p && p->lchild) {
        p=p->lchild;
    }

    return p;
}
node * bst::Delete(node*p,int key) {
    if (!p) {
        return 0;
    }
    if (!p->lchild && !p->rchild) {
        if (p==root) {
            root=0;
        }
        p=0;
        return 0;
    }
    if (key<p->data) {
             cout<<"b"<<endl;
        p->lchild=Delete(p->lchild,key);
    } else if (key>p->data) {
        cout<<"a"<<endl;
        p->rchild=Delete(p->rchild,key);
    } else {
        cout<<height(p->rchild)<<"height"<<endl;
        node *q =new node;
        if (height(p->lchild)>height(p->rchild)) {

            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        } else {
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
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

    t->root=t->RInsert(t->root,50);
    t->RInsert(t->root,10);
    t->RInsert(t->root,40);
    t->RInsert(t->root,20);
    t->RInsert(t->root,30);
    t->Delete(t->root,10);
    t->inorderit(t->root);
    cout<<"-----------"<<endl;
    t->postorder(t->root);
    return 0;
}
