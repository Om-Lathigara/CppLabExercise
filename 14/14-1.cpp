// INSERTION SORT
#include <iostream>
using namespace std;

int main(){
    int a[100],n,i,j,x;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    for(i=1;i<n;i++){
        x=a[i];
        j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }

    for(i=0;i<n;i++) cout<<a[i]<<" ";
}
