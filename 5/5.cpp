#include <iostream>
using namespace std;

class N {
public:
    int c,p;
    N* n;
    N(int a,int b){ c=a; p=b; n=NULL; }
};

N* ins(N* h,int c,int p){
    N* q=new N(c,p);
    if(h==NULL) return q;
    N* t=h;
    while(t->n) t=t->n;
    t->n=q;
    return h;
}

N* add(N* a,N* b){
    N* r=NULL;
    while(a && b){
        if(a->p==b->p){
            r=ins(r,a->c+b->c,a->p);
            a=a->n; b=b->n;
        } else if(a->p>b->p){
            r=ins(r,a->c,a->p);
            a=a->n;
        } else {
            r=ins(r,b->c,b->p);
            b=b->n;
        }
    }
    while(a){ r=ins(r,a->c,a->p); a=a->n; }
    while(b){ r=ins(r,b->c,b->p); b=b->n; }
    return r;
}

N* sub(N* a,N* b){
    N* r=NULL;
    while(a && b){
        if(a->p==b->p){
            r=ins(r,a->c-b->c,a->p);
            a=a->n; b=b->n;
        } else if(a->p>b->p){
            r=ins(r,a->c,a->p);
            a=a->n;
        } else {
            r=ins(r,-b->c,b->p);
            b=b->n;
        }
    }
    while(a){ r=ins(r,a->c,a->p); a=a->n; }
    while(b){ r=ins(r,-b->c,b->p); b=b->n; }
    return r;
}

N* mul(N* a,N* b){
    N* r=NULL;
    for(N* x=a;x;x=x->n){
        for(N* y=b;y;y=y->n){
            int cc=x->c*y->c;
            int pp=x->p+y->p;
            N* t=r;
            N* prev=NULL;
            while(t && t->p>pp){
                prev=t;
                t=t->n;
            }
            if(t && t->p==pp){
                t->c+=cc;
            } else {
                N* q=new N(cc,pp);
                if(prev==NULL){ q->n=r; r=q; }
                else{ q->n=prev->n; prev->n=q; }
            }
        }
    }
    return r;
}

void printp(N* h){
    while(h){
        cout<<h->c<<"x^"<<h->p<<" ";
        h=h->n;
    }
    cout<<endl;
}

int main(){
    int m,n,i,c,p;
    N* a=NULL;
    N* b=NULL;

    cin>>m;
    for(i=0;i<m;i++){
        cin>>c>>p;
        a=ins(a,c,p);
    }

    cin>>n;
    for(i=0;i<n;i++){
        cin>>c>>p;
        b=ins(b,c,p);
    }

    N* s1=add(a,b);
    N* s2=sub(a,b);
    N* s3=mul(a,b);

    printp(s1);
    printp(s2);
    printp(s3);
}
