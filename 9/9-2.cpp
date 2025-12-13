// CIRCULAR QUEUE (ARRAY)
#include <iostream>
using namespace std;

int main(){
    int a[100],f=-1,r=-1,n,x,ch;
    cin>>n;

    while(cin>>ch){
        if(ch==1){
            cin>>x;
            if((r+1)%n==f) cout<<"full\n";
            else{
                if(f==-1) f=0;
                r=(r+1)%n;
                a[r]=x;
            }
        }
        else if(ch==2){
            if(f==-1) cout<<"empty\n";
            else{
                cout<<a[f]<<endl;
                if(f==r) f=r=-1;
                else f=(f+1)%n;
            }
        }
        else if(ch==3){
            if(f==-1) cout<<"empty\n";
            else cout<<a[f]<<endl;
        }
        else if(ch==4){
            if(f==-1) cout<<"empty\n";
            else{
                int i=f;
                while(true){
                    cout<<a[i]<<" ";
                    if(i==r) break;
                    i=(i+1)%n;
                }
                cout<<endl;
            }
        }
        else break;
    }
}
