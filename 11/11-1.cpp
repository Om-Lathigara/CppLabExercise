// BFS TRAVERSAL
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

    int q[100],f=0,r=-1;

    vis[s]=1;
    q[++r]=s;

    while(f<=r){
        int u=q[f++];
        cout<<u<<" ";
        for(j=0;j<n;j++){
            if(g[u][j]==1 && vis[j]==0){
                vis[j]=1;
                q[++r]=j;
            }
        }
    }
}
