#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,u,v,ans=0;
int dp[200005][2];
vector <list<int>> path(200005);
bitset <200005> vis;

int sol(int u,int pa){
    if(vis[u]){
        return dp[u][1];
    }

    int use=0,notuse=0;

    for(auto v:path[u]){
        if(v==pa) continue;
        sol(v,u);
        notuse += dp[v][1];
    }

    for(auto v:path[u]){
        if(v==pa) continue;

        int temp = 1 + dp[v][0] + notuse - dp[v][1];

        use = max(use,temp);
    }

    dp[u][0]=notuse;
    dp[u][1]=use;

    vis[u]=1;


    return max(dp[u][0],dp[u][1]);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    memset(dp,0,sizeof(dp));

    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    sol(1,-1);

    cout << max(dp[1][0],dp[1][1]);
}