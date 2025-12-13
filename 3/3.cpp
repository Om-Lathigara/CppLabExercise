#include <iostream>
using namespace std;

class N {
public:
    int v;
    N* n;
    N(int x){ v=x; n=NULL; }
};

int main(){
    int x,p,i;
    N* h=NULL;
    N* t=NULL;

    // build list
    int m; 
    cin>>m;
    for(i=0;i<m;i++){
        cin>>x;
        N* q=new N(x);
        if(h==NULL){ h=q; t=q; }
        else{ t->n=q; t=q; }
    }

    // traversal
    N* c=h;
    while(c){ cout<<c->v<<" "; c=c->n; }
    cout<<endl;

    // search
    cin>>x;
    c=h;
    p=-1; i=0;
    while(c){
        if(c->v==x){ p=i; break; }
        c=c->n; i++;
    }
    cout<<p<<endl;

    // insertion at position p
    cin>>p>>x;
    N* q=new N(x);
    if(p==0){
        q->n=h;
        h=q;
    } else {
        c=h;
        for(i=0;i<p-1;i++) c=c->n;
        q->n=c->n;
        c->n=q;
    }

    // deletion at position p
    cin>>p;
    if(p==0){
        c=h;
        h=h->n;
        delete c;
    } else {
        c=h;
        for(i=0;i<p-1;i++) c=c->n;
        N* d=c->n;
        c->n=d->n;
        delete d;
    }

    // final print
    c=h;
    while(c){ cout<<c->v<<" "; c=c->n; }
}
