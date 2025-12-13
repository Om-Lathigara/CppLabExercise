#include <iostream>
using namespace std;

class N {
public:
    int v;
    N* n;
    N(int x){ v=x; n=NULL; }
};

int main(){
    int m,n,i,x;

    // first sorted list
    cin>>m;
    N* h1=NULL;
    N* t1=NULL;
    for(i=0;i<m;i++){
        cin>>x;
        N* q=new N(x);
        if(h1==NULL){ h1=q; t1=q; }
        else{ t1->n=q; t1=q; }
    }

    // second sorted list
    cin>>n;
    N* h2=NULL;
    N* t2=NULL;
    for(i=0;i<n;i++){
        cin>>x;
        N* q=new N(x);
        if(h2==NULL){ h2=q; t2=q; }
        else{ t2->n=q; t2=q; }
    }

    // merge
    N* h=NULL;
    N* t=NULL;
    N* a=h1;
    N* b=h2;

    while(a && b){
        N* q;
        if(a->v < b->v){
            q=new N(a->v);
            a=a->n;
        } else {
            q=new N(b->v);
            b=b->n;
        }
        if(h==NULL){ h=q; t=q; }
        else{ t->n=q; t=q; }
    }

    while(a){
        N* q=new N(a->v);
        if(h==NULL){ h=q; t=q; }
        else{ t->n=q; t=q; }
        a=a->n;
    }

    while(b){
        N* q=new N(b->v);
        if(h==NULL){ h=q; t=q; }
        else{ t->n=q; t=q; }
        b=b->n;
    }

    // print merged list
    N* c=h;
    while(c){ cout<<c->v<<" "; c=c->n; }
}
