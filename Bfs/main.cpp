//Basic Bfs Algorithm
#include <bits/stdc++.h>

using namespace std;
vector<int>ad[100005],path;
bool vis[100005];
int dist[100005],parent[100005];

int bfs(int src, int dst)
{
    memset(dist, -1, sizeof dist);
    memset(vis, false, sizeof vis);
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dist[src]=0;
    parent[src]=-1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==dst) return dist[dst];
        for(int v: ad[u])
        {
            if(!vis[v])
            {
                q.push(v);
                parent[v]=u;
                dist[v]=dist[u]+1;
                vis[v]=true;
            }
        }
    }
    return -1;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m; //node, edge
    for(i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    int src,dst;
    cin>>src>>dst;
    int ans=bfs(src,dst);
    if(ans==-1)
    {
        cout<<"Can not reach!!!"<<endl;
    }
    else
    {
        cout<<"shortest distance is: "<<ans<<endl;
        cout<<"Path is: ";
        while(dst!=-1)
        {
            path.push_back(dst);
            dst=parent[dst];
        }
        reverse(path.begin(),path.end());
        for(int p: path)
        {
            cout<<p<<' ';
        }
        cout<<endl;
    }
    return 0;
}

/*
10 13 //node, edge
1 2
1 3
1 4
2 6
3 7
3 8
4 7
5 8
5 10
6 10
7 8
7 9
9 10
1 10 //src, dest
*/
