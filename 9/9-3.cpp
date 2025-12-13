// CIRCULAR QUEUE (LINKED LIST)
#include <iostream>
using namespace std;

class N{
public:
    int v;
    N* n;
    N(int x){ v=x; n=NULL; }
};

int main(){
    N* f=NULL;
    N* r=NULL;
    int x,ch;

    while(cin>>ch){
        if(ch==1){
            cin>>x;
            N* q=new N(x);
            if(f==NULL){
                f=q; r=q;
                r->n=f;
            } else {
                r->n=q;
                r=q;
                r->n=f;
            }
        }
        else if(ch==2){
            if(f==NULL) cout<<"empty\n";
            else{
                cout<<f->v<<endl;
                if(f==r){
                    delete f;
                    f=r=NULL;
                } else {
                    N* t=f;
                    f=f->n;
                    r->n=f;
                    delete t;
                }
            }
        }
        else if(ch==3){
            if(f==NULL) cout<<"empty\n";
            else cout<<f->v<<endl;
        }
        else if(ch==4){
            if(f==NULL) cout<<"empty\n";
            else{
                N* t=f;
                while(true){
                    cout<<t->v<<" ";
                    t=t->n;
                    if(t==f) break;
                }
                cout<<endl;
            }
        }
        else break;
    }
}
