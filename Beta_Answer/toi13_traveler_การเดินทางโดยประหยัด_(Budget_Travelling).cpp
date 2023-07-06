#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,ll>
#define db 0

int N,M,S,E,u,v;
vector <pair<int,ll>> path[100005];
ll dp[2][100005], bud,w;

int DFS(int S,int s){
    queue <pair<ll,int>> q;
    q.push({0,S});
    dp[s][S]=0;
    while(!q.empty()){
        u=q.front().sd;
        w=q.front().ft;
        q.pop();

        if(dp[s][u]<w) continue;

        for(auto [v,ww]:path[u]){
            if(dp[s][v]<=dp[s][u]+ww) continue;

            dp[s][v]=dp[s][u]+ww;
            q.push({(dp[s][u]+ww),v});
        }
    }
}

int main(){
    //USA();
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0x3f,sizeof(dp));

    cin >> N >> M;
    cin >> S >> E >> bud;
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
        path[v].push_back({u,w});
    }

    DFS(S,0);
    DFS(E,1);

    int id=N+1;
    //ll ans=LLONG_MAX;
    for(int i=0;i<N;i++){
        //if(i==S) continue;
        if(dp[0][i]>=1e18||dp[1][i]>=1e18) continue;

        if(dp[1][i]<dp[1][id]&& dp[0][i]<=bud){
            id=i;
        }
    }

    cout << id << " " << dp[0][id] << " " << dp[1][id];
}

