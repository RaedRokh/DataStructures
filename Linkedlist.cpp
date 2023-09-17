#include <iostream>

using namespace std;


class node {
  public:
    int data;
    node *next;
};

node *first=0;
node* first2=0;
node*last=0;
node* create(int A[],int n) {
    int i;
    node *t,*last;
    node *f=new node;
    f->data=A[0];
    f->next=0;
    last=f;
    for (i=1; i<n; i++) {
        t=new node;
        t->data=A[i];
        t->next=0;
        last->next=t;
        last=t;
    }
    return f;
}

void display(node *p) {
    while (p!=0) {
        cout<<p->data<<endl;
        p=p->next;

    }
}


void rdisplay(node *p) {
    if (p!=0) {
        cout<<p->data<<endl;
        rdisplay(p->next);
    }

}
int Count(node *p) {
    if (p==0) {
        return 0;
    }
    return 1+Count(p->next);
}
int sum(node *p) {
    int s=0;
    while (p) {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Max(int currentmax,node *currentnode) {
    if (currentnode->next==0) {
        return currentmax;
    }
    return currentnode->data>currentmax?Max(currentnode->data,currentnode->next):Max(currentmax,currentnode->next);

}
node * rsearch(node *p, int key) {
    if (p==0) {
        return nullptr;
    }
    if (p->data==key) {
        return p;
    }
    rsearch(p->next,key);
}
void Search(node *p,int key) {
    node *q=nullptr;
    while (p!=0) {
        if  (key==p->data) {
            cout<<p->data<<endl;
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
}
void Insert(int pos,int key) {
    node *temp=new node;
    temp->data=key;
    temp->next=nullptr;
    if (pos==0) {
        temp->next=first;
        first=temp;
    } else {
        node *p=first;
        for (int i=0; i<pos-1 && p; i++) {
            p=p->next;
        }
        if (p) {
            temp->next=p->next;
            p->next=temp;
        }
    }
}
void InsertLast(node * f,int key) {
    node * temp=new node;
    temp->data=key;
    temp->next=nullptr;
    if (f==0) {
        f=last=temp;
    } else {
        last->next=temp;
        last=temp;
    }
}
void InsertSorted(int key) {
    node * temp=new node;
    temp->data=key;
    temp->next=nullptr;
    if (first==0) {
        first=temp;
        return;
    }
    if (key<first->data) {
        temp->next=first;
        first=temp;
    } else {
        node *p=first,*q;
        while (p && p->data<key) {
            q=p;
            p=p->next;
        }
        q->next=temp;
        temp->next=p;
    }
}


int Delete(int pos) {
    int x;
    if (pos==0) {
        node *p=first;
        first=first->next;
        x=p->data;
        delete p;
    } else {
        node *p=first,*q;
        for (int i=0; i<pos && p; i++) {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
        delete p;
    }
    return x;
}
bool isSorted(node *p) {
    if (p==0 || p->next==0) {
        return 1;
    }
    while (p->data<p->next->data && p->next->next) {
        p=p->next;
    }
    if (p->data<p->next->data) {
        return true;
    } else return false;
}
void DeleteDupSorted() {
    node*p=first,*q=p->next;
    while (q) {
        if (p->data!=q->data) {
            p=q;
            q=q->next;
        } else {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void Reverse() {
    node *r=0,*q=0;
    node *p=first;
    while (p) {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void ReverseR(node*q,node* p) {
    if (p) {
        ReverseR(p,p->next);
        p->next=q;
    } else {
        first=q;
    }
}
void concatenate(node* f, node * f2) {
    node*p=f;
    while (p->next) {
        p=p->next;
    }
    p->next=f2;
    f2=0;
}
node* MergeSorted(node*f,node *f2) {
    node *third=0, *last=0;
    if (f->data<f2->data) {
        third=f;
        last=f;
        f=f->next;
        last->next=0;
    } else {
        third=f2;
        last=f2;
        f2=f2->next;
        last->next=0;
    }
    while (f && f2) {
        if (f->data<f2->data) {
            last->next=f;
            last=f;
            f=f->next;
            last->next=0;
        } else if (f->data>f2->data) {
            last->next=f2;
            last=f2;
            f2=f2->next;
            last->next=0;
        } else {
            last->next=f2;
            last=f2;
            f2=f2->next;
            f=f->next;
            last->next=0;
        }
    }
    if (f) {
        last->next=f;
    }
    if (f2) {
        last->next=f2;
    }
    return third;
}
bool isLoop(node* f) {
    node*a=f,*b=f;
    do {
        a=a->next;
        b=b->next;
        b=(b?b->next:0);
    } while (a && b && a!=b);

    return (a==b?true:false);

}
void displayc(node *p) {
    static int flag=0;
    if (p!=first || flag==0) {
        flag=1;
        cout<<p->data;
        display(p->next);

    }
    flag=0;
}
int findmiddle(node*p) {

    node*a=p,*b=p;
    while(b) {
        b=b->next;
        if (b) b=b->next;
        if (b) a=a->next;
    }
    return a->data;

}
//int main() {
//
//    int A[]= {1,3,4,5,7};
//    first=create(A,5);
//    Insert(0,0);
//    display(first);
//    return 0;
//}


