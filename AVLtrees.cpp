#include "Binarytreeusingqueue.cpp"
using namespace Q;

class avl:public tree {
  public:
    node * RInsert(node * p,int key);
    node *LLrotation(node *p);
    node *LRrotation(node *p);
    node *RRrotation(node *p);
    node *RLrotation(node *p);
    node * Delete(node *p,int key);
};
int nodeheight(node *p) {
    int hr=p && p->rchild?p->rchild->height:0;
    int hl=p && p->lchild?p->lchild->height:0;

    return hl>=hr?hl+1:hr+1;
}
int balancefactor(node *p) {
    int hr=p && p->rchild?p->rchild->height:0;
    int hl=p && p->lchild?p->lchild->height:0;

    return hl-hr;
}
node * inpre(node * p) {
    while (p && p->rchild) {
        p=p->rchild;
    }
    return p;
}
node * insucc(node * p) {
    while (p && p->lchild) {
        p=p->lchild;
    }

    return p;
}
node * avl::Delete(node *p,int key) {
//     cout<<p->data<<"lena"<<balancefactor(p)<<endl;
    if (!p) {
        return 0;
    }
    if (!p->rchild && !p->lchild) {
        if (p==root) {
            root=0;
        }
        p=0;
        return 0;
    }
    if (p->data<key) {

        p->rchild=Delete(p->rchild,key);
        p->height=nodeheight(p);
        if (balancefactor(p)==2 && balancefactor(p->lchild)==1) {

            return LLrotation(p);

        } else if (balancefactor(p)==2 && balancefactor(p->lchild)==-1) {
            return LRrotation(p);
        }
        if (balancefactor(p)==2 && balancefactor(p->lchild)==0) {
            return LLrotation(p);
        }
    } else if (p->data>key) {
        p->lchild=Delete(p->lchild,key);
        p->height=nodeheight(p);
        if (balancefactor(p)==-2 && balancefactor(p->rchild)==-1) {
            return RRrotation(p);
        } else if (balancefactor(p)==-2 && balancefactor(p->rchild)==1) {
            return RLrotation(p);
        }
        if (balancefactor(p)==-2 && balancefactor(p->rchild)==0) {
            return RRrotation(p);
        }
    } else {

        node *t=new node;
        if (balancefactor(p)<0) {

            t=insucc(p->rchild);
            p->data=t->data;
            p->rchild=Delete(p->rchild,t->data);


        } else {
            t=inpre(p->lchild);
            p->data=t->data;
            p->lchild=Delete(p->lchild,t->data);

        }


    }

    return p;
}

node *avl::LLrotation(node *p) {
    node*pl=p->lchild;
    node *plr=pl->rchild?pl->rchild:0;

    pl->rchild=p;
    p->lchild=plr;
    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    if (root==p) {
        root=pl;
    }
    return root;

}
node *avl::RRrotation(node *p) {
    node*pr=p->rchild;
    node *prl=pr->lchild?pr->lchild:0;

    pr->lchild=p;
    p->rchild=prl;
    pr->height=nodeheight(pr);
    p->height=nodeheight(p);
    if (root==p) {
        root=pr;
    }
    return root;

}
node *avl::RLrotation(node *p) {
    node*pr=p->rchild;
    node *prl=pr->lchild?pr->lchild:0;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->lchild=p;
    prl->rchild=pr;

    pr->height=nodeheight(pr);
    prl->height=nodeheight(prl);
    p->height=nodeheight(p);
    if (root==p) {
        root=prl;
    }
    return root;

}
node *avl::LRrotation(node *p) {
    node*pl=p->lchild;
    node *plr=pl->rchild?pl->rchild:0;
    p->lchild=plr->rchild;
    pl->rchild=plr->lchild;
    plr->rchild=p;
    plr->lchild=pl;
    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);
    if (root==p) {
        root=plr;
    }
    return root;

}
node
* avl::RInsert(node * p,int key) {

    if (!p) {
        node *t=new node;
        t->data=key;
        t->height=1;
        return t;
    } else if (p->data<key) {
        p->rchild=RInsert(p->rchild,key);
    } else {
        p->lchild=RInsert(p->lchild,key);
    }

    p->height=nodeheight(p);
    if (balancefactor(p)==2 && balancefactor(p->lchild)==1) {

        return LLrotation(p);
    } else if (balancefactor(p)==2 && balancefactor(p->lchild)==-1) {

        return LRrotation(p);
    } else if (balancefactor(p)==-2 && balancefactor(p->rchild)==-1) {

        return RRrotation(p);
    } else if (balancefactor(p)==-2 && balancefactor(p->rchild)==1) {
        return RLrotation(p);
    }

    return p;
}


int main() {
    avl *l=new avl;
    l->root=l->RInsert(l->root,30);
    l->RInsert(l->root,10);
    l->RInsert(l->root,40);
    l->RInsert(l->root,20);
     l->RInsert(l->root,5);
    l->Delete(l->root,40);
    l->preorder(l->root);
    return 0;
}
