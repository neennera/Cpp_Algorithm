#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<double,int>
#define db 0
 
int N,M,u,w,v,Q;
vector <list <pair<int,ll>>> path(200005);
ll ans[200005];
ll dp[200005];
priority_queue <ll> dist;
priority_queue <int> penguin;
 
ll ev(int u,int p){
    ll temp=0;
    for(auto [v,w]:path[u]){
        if(v==p) continue;
        temp=max(temp,w+ev(v,u));
    }
    return dp[u]=temp;
}
 
ll DFS(int u,int pa, ll patial){
    ll op1,op2;
    vector <ll> pf, sf;
    for(auto [v,w]:path[u]){
        if(v==pa){
            // if it patial, it now reach to node u -> can use patial
            ans[u]=max(ans[u], patial);
            continue;
        }
        //pf sf must add w to reach from v to u
        // since dp[v] only consider node below v (u is not include)
        ans[u]=max(ans[u], dp[v]+w);
        pf.push_back(dp[v]+w);
        sf.push_back(dp[v]+w);
    }
    int n=pf.size();
    for(int i=1;i<n;i++){        
        pf[i]=max(pf[i],pf[i-1]);
        sf[n-i-1]=max(sf[n-i-1],sf[n-i]);
    }
 
    int ct=0;
    for(auto [v,w]:path[u]){
        if(v==pa) continue;
        //if it no node in left,right -> be 0
        op1= (ct==0) ? 0: pf[ct-1];
        op2= (ct==n-1) ? 0 : sf[ct+1];
        // add w to reach to node v with path[u,v,w]
        DFS(v,u,w+max(patial,max(op1,op2)));
        ct++;
    }
    // ans[u]=1+max(patial,(pf.empty()) ? -1 : pf.back());
    dist.push(-1*ans[u]);
    return ans[u];
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> N >> M;
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<N-1;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
        path[v].push_back({u,w});
    }
 
    ev(1,0);
    DFS(1,0,-1);
 
    for(int i=0;i<M;i++){
        int u;
        cin >> u;
        penguin.push(u);
    }

    ll sum=0;
    while(M--){
        sum += penguin.top()*dist.top()*-1;
        penguin.pop(), dist.pop();
    }
    cout << sum;
}
