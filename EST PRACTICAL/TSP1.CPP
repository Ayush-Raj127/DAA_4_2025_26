#include <bits/stdc++.h>
using namespace std;

int m;
int cost[16][16];
int memo[16][1<<16];

int solve(int cur,int vis)
{
    if(vis==(1<<m)-1)
        return cost[cur][0];

    if(memo[cur][vis]!=-1)
        return memo[cur][vis];

    int res=1e9;

    for(int nxt=0;nxt<m;nxt++)
    {
        if((vis&(1<<nxt))==0)
            res=min(res,cost[cur][nxt]+solve(nxt,vis|(1<<nxt)));
    }

    return memo[cur][vis]=res;
}

int main()
{
    cin>>m;

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>cost[i][j];

    memset(memo,-1,sizeof(memo));

    cout<<solve(0,1);

    return 0;
}