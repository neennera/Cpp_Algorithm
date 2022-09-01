#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define ll long long
#define pii pair<int,int>

int N,M,u,v,w;
vector <list<int>> path(100005);
bitset <100005> vis;
ll dp[100005];
int pa[100005];

void solve(){
    stack <pii> q;
    q.push({1,1});

    while(!q.empty()){
        u=q.top().ft;
        w=q.top().sd;
        q.pop();

        if(w<dp[u]) continue;

        for(int v:path[u]){
            if(dp[v]<dp[u]+1){
                dp[v]=dp[u]+1;
                pa[v]=u;
                q.push({v,dp[v]});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    memset(pa,0,sizeof(pa));
    memset(dp,0,sizeof(dp));
    
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
    }

    solve();

    if(dp[N]==0){
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << dp[N]+1 << "\n";
    int u=N;
    stack <int> ans;
    while(u!=1){
        ans.push(u);
        u=pa[u];
    }
    ans.push(1);
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
}