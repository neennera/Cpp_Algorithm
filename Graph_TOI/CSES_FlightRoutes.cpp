//link : https://cses.fi/problemset/task/1196
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>

int N,M,K,u,v;
ll w;
vector <vector<ll>> dp;
vector <vector<pii>> path;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    
    dp.resize(N+1);
    path.resize(N+1);
    for(int i=0;i<=N;i++){
        dp[i].resize(K,9e15);
    }

    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
    }
    
    priority_queue <pii,vector<pii>, greater <pii>> pq; //important
    pq.push({0,1});
    dp[1][0]=0;
    while(!pq.empty()){
        u=pq.top().sd;
        w=pq.top().ft;  // w must be long long
        pq.pop();

        if(dp[u][K-1]<w) continue;  //important

        for(auto [v,ww]: path[u]){
            if(dp[v][K-1]<=w+ww) continue;
            dp[v][K-1] = w+ww;
            sort(dp[v].begin(), dp[v].end());
            pq.push({w+ww,v});
        }
    }
    for(auto x:dp[N]){
        cout << x << " ";
    }
}