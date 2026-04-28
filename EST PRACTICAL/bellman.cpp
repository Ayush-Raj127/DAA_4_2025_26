#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int u,v,c;
};

int main()
{
    int V,E,src;
    cin>>V>>E>>src;

    vector<Node> g(E);

    for(int i=0;i<E;i++)
        cin>>g[i].u>>g[i].v>>g[i].c;

    vector<int> dis(V,1e9);
    dis[src]=0;

    for(int k=1;k<V;k++)
    {
        for(int i=0;i<E;i++)
        {
            if(dis[g[i].u]!=1e9 && dis[g[i].u]+g[i].c<dis[g[i].v])
                dis[g[i].v]=dis[g[i].u]+g[i].c;
        }
    }

    for(int i=0;i<V;i++)
        cout<<dis[i]<<" ";

    return 0;
}