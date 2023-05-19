#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<double,int>
#define db 0
 
int N,u,v,Q;
vector <list<int>> path(200005);
ll ans[200005];
ll dp[200005];
 
ll ev(int u,int p){
    ll temp=0;
    for(auto v:path[u]){
        if(v==p) continue;
        temp=max(temp,1+ev(v,u));
    }
 
    return dp[u]=temp;
}
 
ll DFS(int u,int pa, ll patial){
    ll op1,op2;
 
    vector <ll> pf, sf;
    for(auto v:path[u]){
        if(v==pa) continue;
 
        pf.push_back(dp[v]);
        sf.push_back(dp[v]);
    }
    int n=pf.size();
    for(int i=1;i<n;i++){
        pf[i]=max(pf[i],pf[i-1]);
        sf[n-i-1]=max(sf[n-i-1],sf[n-i]);
    }
 
    int ct=0;
    for(auto v:path[u]){
        if(v==pa) continue;
 
        op1= (ct==0) ? -1 : pf[ct-1];
        op2= (ct==n-1) ? -1 : sf[ct+1];
        DFS(v,u,1+max(patial,max(op1,op2)));
        ct++;
    }
 
    return ans[u]=1+max(patial,(pf.empty()) ? -1 : pf.back());
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> N;
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
 
    ev(1,0);
    DFS(1,0,-1);
 
    for(int i=1;i<=N;i++) cout << ans[i] << " ";
}