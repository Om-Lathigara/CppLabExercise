// TREE TRAVERSALS: PREORDER, INORDER, POSTORDER
#include <iostream>
using namespace std;

class N{
public:
    int v;
    N *l,*r;
    N(int x){ v=x; l=r=NULL; }
};

void pre(N* r){
    if(r==0) return;
    cout<<r->v<<" ";
    pre(r->l);
    pre(r->r);
}

void in(N* r){
    if(r==0) return;
    in(r->l);
    cout<<r->v<<" ";
    in(r->r);
}

void post(N* r){
    if(r==0) return;
    post(r->l);
    post(r->r);
    cout<<r->v<<" ";
}

int main(){
    int n,x;
    cin>>n;

    N* a[100];
    for(int i=0;i<n;i++){
        cin>>x;
        a[i]=new N(x);
    }

    for(int i=0;i<n;i++){
        int l=2*i+1;
        int r=2*i+2;
        if(l<n) a[i]->l=a[l];
        if(r<n) a[i]->r=a[r];
    }

    N* root=a[0];

    pre(root); cout<<endl;
    in(root); cout<<endl;
    post(root); cout<<endl;
}
