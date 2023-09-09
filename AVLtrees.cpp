#include "Binarytreeusingqueue.cpp"
using namespace Q;

class avl:public tree {
  public:
    node * RInsert(node * p,int key);
    node *LLrotation(node *p);
    node *LRrotation(node *p);
};

int nodeheight(node *p){
int hr=p && p->rchild?p->rchild->height:0;
int hl=p && p->lchild?p->lchild->height:0;
cout<<p->data<<" wow "<<" wow "<<hl<<endl;
return hl>=hr?hl+1:hr+1;
 }
int balancefactor(node *p){
int hr=p && p->rchild?p->rchild->height:0;
int hl=p && p->lchild?p->lchild->height:0;
return hl-hr;
}
node *avl::LLrotation(node *p){
node*pl=p->lchild;
node *plr=pl->rchild?pl->rchild:0;

pl->rchild=p;
p->lchild=plr;
pl->height=nodeheight(pl);
p->height=nodeheight(p);
if (root==p){
    root=pl;}
return root;

}
node *avl::LRrotation(node *p){
node*pl=p->lchild;
node *plr=pl->rchild?pl->rchild:0;

p->lchild=plr->rchild;
pl->rchild=plr->lchild;
plr->rchild=p;
plr->lchild=pl;
if (root==p){
    root=plr;}
return root;

}
node
* avl::RInsert(node * p,int key){

if (!p){
        cout<<"b"<<endl;
    node *t=new node;
    t->data=key;
    t->height=1;
    return t;
}
else if (p->data<key){
cout<<"d"<<endl;
    p->rchild=RInsert(p->rchild,key);
}
else{
        cout<<"a"<<endl;
    p->lchild=RInsert(p->lchild,key);
}

p->height=nodeheight(p);
cout<<p->data<<"-----"<<p->height<<endl;
if (balancefactor(p)==2 && balancefactor(p->lchild)==1){

    return LLrotation(p);
}
else if (balancefactor(p)==2 && balancefactor(p->lchild)==-1){
        cout<<"lekhra"<<p->data<<endl;
    return LRrotation(p);
}
//else if (balancefactor(p)==-2 && balancefactor(p)==-1){
//    return RRrotation(p);
//}
//else if (balancefactor(p)==-2 && balancefactor(p)==1){
//    return RLrotation(p);
//}
//else {cout<<"wtf"<<endl;}

return p;
}


int main(){
    avl *l=new avl;
    l->root=l->RInsert(l->root,10);
    l->RInsert(l->root,5);
    l->RInsert(l->root,8);
    l->preorder(l->root);
return 0;}
