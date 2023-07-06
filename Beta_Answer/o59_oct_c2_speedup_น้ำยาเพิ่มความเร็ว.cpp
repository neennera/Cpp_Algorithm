#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

struct DATA{
    int u; 
    ll w;
    int use, pa;
    bool operator <(const DATA&d2) const{
        return w > d2.w;
    }
};

int N,M,L,Q,u,v;
vector<pair<int,ll>> g[80005];
bool drink[80005];
ll dp[80005][9],w,ww;    //how many drink
priority_queue<DATA> pq;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    cin >> N >> M >> L >> Q;
    for(int i=0;i<M;i++){
        cin>> u >> v >> w;
        g[u].push_back({v,w});
    }
    for(int i=0;i<L;i++){
        int a; cin >> a;
        drink[a]=1;
    }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=8;j++){
            dp[i][j] = LONG_LONG_MAX;
        }
    }

    pq.push({1,0,0,-1});
    dp[1][0]=0;
    while(!pq.empty()){
        auto [u,w,use,pa] = pq.top(); pq.pop();
        
        if(u==N){   //the end
            cout << w; return 0;
        }

        if(drink[u]&&use<Q&&pa!=u){ //choose to drink
            for(auto x:g[u]){
                v = x.first;
                ww = (x.second)>>(use+1);   //devide by speed
                if(dp[v][use+1]>dp[u][use]+ww){
                    dp[v][use+1]=dp[u][use]+ww;
                    pq.push({v,dp[v][use+1],use+1,u});
                }
            }
        }

        for(auto x:g[u]){
            v=x.first;
            ww=(x.second)>>(use);
            if(dp[v][use]>dp[u][use]+ww){
                dp[v][use]=dp[u][use]+ww;
                pq.push({v,dp[v][use],use,pa});
            }
        }
    }
    return 0;
}
