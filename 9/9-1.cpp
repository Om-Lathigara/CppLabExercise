// LINEAR QUEUE (ARRAY)
#include <iostream>
using namespace std;

int main(){
    int a[100],f=0,r=-1,n,x,ch;
    cin>>n;

    while(cin>>ch){
        if(ch==1){
            cin>>x;
            if(r==n-1) cout<<"full\n";
            else a[++r]=x;
        }
        else if(ch==2){
            if(f>r) cout<<"empty\n";
            else cout<<a[f++]<<endl;
        }
        else if(ch==3){
            if(f>r) cout<<"empty\n";
            else cout<<a[f]<<endl;
        }
        else if(ch==4){
            if(f>r) cout<<"empty\n";
            else{
                for(int i=f;i<=r;i++) cout<<a[i]<<" ";
                cout<<endl;
            }
        }
        else break;
    }
}
