#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
struct DATA{
    int u;
    ll w;
    int n;
    bool operator < (const DATA & d2) const{
        if(w==d2.w) return n>d2.n;
        return w>d2.w;
    }
};
int N,M,S,E;
int u,v,Q,wt,n;
ll w;
vector <pair<int,int>> path[2005];
vector <pair<ll,int>> d[2005];

int cal(){
    priority_queue <DATA> q;
    q.push({S,0,0});
    d[S].push_back({0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        n=q.top().n;
        q.pop();

        for(auto x:path[u]){
            int v=x.ft;
            ll ww=x.sd;
            bool c=1;
            for(auto m:d[v]){
                if(m.ft <= w+ww && m.sd<= n+1){
                    c=0;
                    break;
                }
            }
            if(c){
                d[v].push_back({w+ww,n+1});
                q.push({v,w+ww,n+1});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> S >> E >> M;
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
    }
    cal();
    cin >> Q;
    for(int i=0;i<Q;i++){
        cin >> wt;
        ll ans=LLONG_MAX;
        for(auto m:d[E]){
            ans=min(ans,(ll)m.ft+(m.sd-1)*wt);
        }
        cout << ans << " ";
    }
}

