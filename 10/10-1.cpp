// DEQUE USING ARRAY
#include <iostream>
using namespace std;

int main(){
    int a[100],f=-1,r=-1,n,ch,x;
    cin>>n;

    while(cin>>ch){
        if(ch==1){              
            cin>>x;             
            if((f==0 && r==n-1) || (r+1)==f) cout<<"full\n";
            else{
                if(f==-1) f=r=0;
                else if(f==0) f=n-1;
                else f--;
                a[f]=x;
            }
        }
        else if(ch==2){         
            cin>>x;
            if((f==0 && r==n-1) || (r+1)==f) cout<<"full\n";
            else{
                if(f==-1) f=r=0;
                else if(r==n-1) r=0;
                else r++;
                a[r]=x;
            }
        }
        else if(ch==3){         
            if(f==-1) cout<<"empty\n";
            else{
                cout<<a[f]<<endl;
                if(f==r) f=r=-1;
                else if(f==n-1) f=0;
                else f++;
            }
        }
        else if(ch==4){         
            if(f==-1) cout<<"empty\n";
            else{
                cout<<a[r]<<endl;
                if(f==r) f=r=-1;
                else if(r==0) r=n-1;
                else r--;
            }
        }
        else if(ch==5){         
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
