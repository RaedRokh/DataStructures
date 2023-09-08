#include "Binarytreeusingqueue.cpp"
using namespace Q;

class bst:public tree {
public:
    void Insert(int key);
};
void bst::Insert(int key) {
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
    t->Insert(10);


    t->inorderit(t->root);
    return 0;
}
