#include <iostream>
using namespace std;

int main(){
    int a[100],top=-1,n,x;
    cin>>n;

    int ch;
    while(cin>>ch){
        if(ch==1){          // push
            cin>>x;
            if(top==n-1) cout<<"full\n";
            else a[++top]=x;
        }
        else if(ch==2){     // pop
            if(top==-1) cout<<"empty\n";
            else cout<<a[top--]<<endl;
        }
        else if(ch==3){     // peek
            if(top==-1) cout<<"empty\n";
            else cout<<a[top]<<endl;
        }
        else if(ch==4){     // isempty
            if(top==-1) cout<<"yes\n";
            else cout<<"no\n";
        }
        else if(ch==5){     // isfull
            if(top==n-1) cout<<"yes\n";
            else cout<<"no\n";
        }
        else if(ch==6){     // size
            cout<<top+1<<endl;
        }
        else break;
    }
}
