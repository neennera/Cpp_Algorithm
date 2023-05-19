#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
 
int N,M,u,v;
ll mod = (ll)1e9 +7;
ll dp[200005];
int dg[200005];
vector <list<int>> path(200005);
vector <list<int>> pathb(200005);
 
void solve(){
    queue <int> q;
    for(int i=1;i<=N;i++){
        if(dg[i]==0){
            q.push(i);
        }
    }
 
    dp[1]=1;
 
    while(!q.empty()){
        u = q.front();
        q.pop();
 
        for(auto v:path[u]){
            dg[v]--;
            if(dg[v]==0){
                q.push(v);
            }                
        }
 
        for(auto p:pathb[u]){
            dp[u]+=dp[p];
            dp[u]%=mod;
        }
 
    }
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    memset(dp,0,sizeof(dp));
    memset(dg,0,sizeof(dg));
 
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
        pathb[v].push_back(u);
        dg[v]++;
    }
 
    solve();
 
    cout << dp[N];
}