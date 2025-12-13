// DFS TRAVERSAL
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int g[20][20],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>g[i][j];

    int s;
    cin>>s;

    int vis[20];
    for(i=0;i<n;i++) vis[i]=0;

    int st[100],top=-1;

    st[++top]=s;

    while(top!=-1){
        int u=st[top--];
        if(vis[u]==0){
            vis[u]=1;
            cout<<u<<" ";
            for(j=n-1;j>=0;j--){
                if(g[u][j]==1 && vis[j]==0){
                    st[++top]=j;
                }
            }
        }
    }
}
