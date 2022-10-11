#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,u,v;
vector <list<int>> path(200005);
ll dp[200005];
ll child[200005];
ll ans[200005];

ll DFS1(int u,int pa){
    child [u] =1;
    for(auto v:path[u]){
        if(v==pa) continue;
        dp[u] += DFS1(v,u) + child[v];
        child[u] += child[v];
    }
    return dp[u];
}

int DFS2(int u,int pa){
    if(u==1){
        ans[u]=dp[u];
    }
    for(auto v:path[u]){
        if(v==pa) continue;
        ans[v] = ans[u] + N -2*child[v];
        DFS2(v,u);
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0,sizeof(dp));
    memset(child,0,sizeof(child));

    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    DFS1(1,-1);
    DFS2(1,-1); 
    
    for(int i=1;i<=N;i++){
        cout << ans[i] << " ";
    }
}