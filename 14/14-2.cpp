// SELECTION SORT
#include <iostream>
using namespace std;

int main(){
    int a[100],n,i,j,p,t;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    for(i=0;i<n-1;i++){
        p=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[p]) p=j;
        }
        t=a[i];
        a[i]=a[p];
        a[p]=t;
    }

    for(i=0;i<n;i++) cout<<a[i]<<" ";
}
