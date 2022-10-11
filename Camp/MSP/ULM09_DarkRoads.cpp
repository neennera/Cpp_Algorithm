#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

struct DATA{
    int u,v;
    ll w;
    bool operator < (const DATA & d2) const{
        return w > d2.w;
    }
};

int pa[200005];
int fp(int n){
    if(pa[n]==n) return n;
    return pa[n]=fp(pa[n]);
}

void solve(int N,int M){
    int u,v;
    ll ans=0,w,all=0;
    priority_queue <DATA> pq;
    memset(pa,0,sizeof(pa));

    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        all += w;
        pq.push({u,v,w});
    }
    for(int i=0;i<N;i++) pa[i]=i;

    while(N>1 && !pq.empty()){
        struct DATA d = pq.top(); pq.pop();
        u=d.u, v=d.v, w=d.w;
        //cout << w << " ";
        int pv=fp(v), pu=fp(u);
        if(pv==pu) continue;

        pa[pv]=pu;
        ans+=w;
    }
    cout << all - ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int Q; cin >> Q;
    while(Q--){
        int N,M;
        cin >> N >> M;
        solve(N,M);
    }
}