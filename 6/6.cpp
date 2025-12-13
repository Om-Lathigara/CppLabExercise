#include <iostream>
using namespace std;

class N {
public:
    int v;
    N *p, *n;
    N(int x){ v=x; p=NULL; n=NULL; }
};

int main(){
    N* h=NULL;
    N* t=NULL;
    int m,i,x,pos;

    // build list
    cin>>m;
    for(i=0;i<m;i++){
        cin>>x;
        N* q=new N(x);
        if(h==NULL){ h=q; t=q; }
        else{
            t->n=q;
            q->p=t;
            t=q;
        }
    }

    // traversal forward
    N* c=h;
    while(c){ cout<<c->v<<" "; c=c->n; }
    cout<<endl;

    // traversal backward
    c=t;
    while(c){ cout<<c->v<<" "; c=c->p; }
    cout<<endl;

    // searching
    cin>>x;
    c=h;
    pos=-1; i=0;
    while(c){
        if(c->v==x){ pos=i; break; }
        c=c->n; i++;
    }
    cout<<pos<<endl;

    // insertion at position pos
    cin>>pos>>x;
    N* q=new N(x);
    if(pos==0){
        q->n=h;
        if(h) h->p=q;
        h=q;
    } else {
        c=h;
        for(i=0;i<pos-1;i++) c=c->n;
        q->n=c->n;
        q->p=c;
        if(c->n) c->n->p=q;
        c->n=q;
        if(q->n==NULL) t=q;
    }

    // deletion at position pos
    cin>>pos;
    if(pos==0){
        c=h;
        h=h->n;
        if(h) h->p=NULL;
        delete c;
    } else {
        c=h;
        for(i=0;i<pos;i++) c=c->n;
        if(c->p) c->p->n=c->n;
        if(c->n) c->n->p=c->p;
        if(c==t) t=c->p;
        delete c;
    }

    // final traversal
    c=h;
    while(c){ cout<<c->v<<" "; c=c->n; }
}
