#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd  second
#define ll long long
#define pii pair<ll,ll>

ll N,S,M;
ll u,v,w;
ll dp[100005];
vector <pii> path[100005];
ll dg[100005]={0};

void USA(string s){
    freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve(){
    queue <int> q;
    for(int i=1;i<=N;i++){
        if(dg[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        u=q.front(); q.pop();

        for(auto [v,w]:path[u]){
            dp[v]=max(dp[v],dp[u]+w);
            dg[v]--;
            if(dg[v]==0)
                q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dg,0,sizeof(dg));

    USA("timeline");

    cin >> N >> S >> M;
    for(int i=1;i<=N;i++) cin >> dp[i];
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
        dg[v]++;
    }

    solve();

    for(int i=1;i<=N;i++)
        cout << dp[i]<< "\n";
}