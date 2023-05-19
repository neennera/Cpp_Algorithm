#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int w[100005];
int pa[100005];
int fp(int n){
    if(pa[n]==n) return n;
    return pa[n]=fp(pa[n]);
}
struct DATA{
    int u,v;
    bool operator < (const DATA & d2) const{
        return w[u]+w[v] < w[d2.u] + w[d2.v];
    }
};
int N,M;
priority_queue <DATA> q;
ll ans=0;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> w[i];
        pa[i]=i;
    }
    int u,v,ru,rv;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        q.push({u,v});
    }
    while(!q.empty()&& N>1){
        u=q.top().u;
        v=q.top().v;
        q.pop();
        ru=fp(u), rv=fp(v);
        if(ru==rv) continue;
        pa[ru]=rv;
        N--;
        ans+=(w[u] + w[v]);
    }
    cout << ans;
}