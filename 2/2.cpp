#include <iostream>
using namespace std;

int main(){
    int a[100],n,i,x,p,v,c;

    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    // traversal
    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    // search
    cin>>x;
    p=-1;
    for(i=0;i<n;i++){
        if(a[i]==x){ p=i; break; }
    }
    cout<<p<<endl;

    // insertion
    cin>>p>>v; 
    for(i=n;i>p;i--) a[i]=a[i-1];
    a[p]=v;
    n++;

    // deletion of one element
    cin>>p;
    for(i=p;i<n-1;i++) a[i]=a[i+1];
    n--;

    // delete all occurrences of an element
    cin>>x;
    for(i=0;i<n;i++){
        if(a[i]==x){
            for(int j=i;j<n-1;j++) a[j]=a[j+1];
            n--;
            i--;
        }
    }

    // frequency of all elements
    for(i=0;i<n;i++){
        c=1;
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                c++;
                for(int k=j;k<n-1;k++) a[k]=a[k+1];
                n--;
                j--;
            }
        }
        cout<<a[i]<<" "<<c<<endl;
    }

    return 0;
}
