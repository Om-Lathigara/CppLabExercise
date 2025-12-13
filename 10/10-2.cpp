// PRIORITY QUEUE (LINKED LIST)
#include <iostream>
using namespace std;

class N{
public:
    int v,p;
    N* n;
    N(int a,int b){ v=a; p=b; n=NULL; }
};

int main(){
    N* h=NULL;
    int ch,x,pr;

    while(cin>>ch){
        if(ch==1){            
            cin>>x>>pr;
            N* q=new N(x,pr);
            if(h==NULL || pr < h->p){
                q->n=h;
                h=q;
            } else {
                N* t=h;
                while(t->n && t->n->p <= pr) t=t->n;
                q->n=t->n;
                t->n=q;
            }
        }
        else if(ch==2){        
            if(h==NULL) cout<<"empty\n";
            else{
                cout<<h->v<<endl;
                N* t=h;
                h=h->n;
                delete t;
            }
        }
        else if(ch==3){        
            if(h==NULL) cout<<"empty\n";
            else{
                N* t=h;
                while(t){
                    cout<<t->v<<"("<<t->p<<") ";
                    t=t->n;
                }
                cout<<endl;
            }
        }
        else break;
    }
}
