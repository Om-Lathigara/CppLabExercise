// BINARY TREE INSERTION (LEVEL ORDER)
#include <iostream>
using namespace std;

class N{
public:
    int v;
    N *l,*r;
    N(int x){ v=x; l=r=NULL; }
};

int main(){
    N* root=NULL;
    int n,x,i;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        N* q=new N(x);

        if(root==NULL){
            root=q;
        } else {
            N* a[100];
            int f=0,r=0;
            a[0]=root;

            while(true){
                N* t=a[f++];
                if(t->l==NULL){
                    t->l=q;
                    break;
                }
                else if(t->r==NULL){
                    t->r=q;
                    break;
                }
                else{
                    a[++r]=t->l;
                    a[++r]=t->r;
                }
            }
        }
    }

    return 0;
}
