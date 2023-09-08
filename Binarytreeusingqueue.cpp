#include "StackusingLL.cpp"
#include "Queueusingarray.cpp"
using namespace Q;
class tree {
  public:
    Q::node *root;
    tree() {
        root=0;
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
    friend void createPre(int pre[], int n);

};

void tree::create() {
    Queue *q=new Q::Queue(100);
    int val;
    cout<<"Enter root value: "<<endl;
    cin>>val;
    root=new node;
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

void tree::preorder(node* p) {
    if (p) {
        cout<<p->data<<endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::postorder(node* p) {
    if (p) {


        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<endl;
    }
}
void tree::inorder(node* p) {
    if (p) {
        inorder(p->lchild);
        cout<<p->data<<endl;
        inorder(p->rchild);
    }
}
void tree::levelorder() {
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
int tree::height(node* root) {
    int x,y;
    if (!root) {
        return 0;
    }
    x=height(root->lchild);
      y=height(root->lchild);
    return x>y?x+1:y+1;
}

void tree::preorderit(node*p) {
    S::Stack<node*> *s=new S::Stack<node*>();
    while (s->top || p) {
        if (p) {
            s->push(p);
            cout<<p->data<<endl;
            p=p->lchild;

        } else {
            p=s->pop();
            p=p->rchild;
        }
    }
}
void tree::inorderit(node*p) {
    S::Stack<node*> *s=new S::Stack<node*>();
    while (s->top || p) {
        if (p) {
            s->push(p);
            p=p->lchild;

        } else {
            p=s->pop();
            cout<<p->data<<endl;
            p=p->rchild;
        }
    }
}
void tree::postorderit(Q::node*p) {
    node * t=p;
    S::Stack<node*> *s=new S::Stack<node*>();
    while(t || s->top) {
        if (t) {
            s->push(t);
            t=t->lchild;
        } else {
            t=s->pop();
            intptr_t address = reinterpret_cast<intptr_t>(t);
            if (address>0) {
                address = -address;
                s->push(reinterpret_cast<node*>(address));
                t=t->rchild;
            } else {
                t = reinterpret_cast<node*>(-address);
                cout<<t->data<<endl;
                t=nullptr;
            }
        }
    }
}
int tree::countnodes(node * p) {
    if (!p) {
        return 0;
    }
    return countnodes(p->lchild)+countnodes(p->rchild)+1;
}
int tree::countleafs(node * p) {
    if (!p) {
        return 0;

    }
    if (!p->lchild || !p->rchild) {
        return countnodes(p->lchild)+countnodes(p->rchild)+1;
    } else {
        return countnodes(p->lchild)+countnodes(p->rchild);
    }


}
//int main() {
//    tree * t=new tree;
//    t->create();
//
//    t->preorder(t->root);
//    t->preorderit(t->root);
//    cout<<t->countleafs(t->root);
//    cout<<"-----------"<<endl;
//    cout<<t->countnodes(t->root);
//        cout<<"-----------"<<endl;
//        cout<<t->height(t->root)<<endl;
//    return 0;
//}
