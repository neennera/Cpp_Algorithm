#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

struct DATA{
    int u,v;
    int w;
    bool operator <(const DATA & d2) const{
        return w<d2.w;
    }
};

int N,M,u,v;
int w;
int pa[200005];
priority_queue <DATA> q;
ll ans=0;

int fp(int n){
    if(pa[n]==n) return n;
    return pa[n]=fp(pa[n]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for(int i=1;i<=N;i++){ pa[i]=i; }

    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        q.push({u,v,w-1});
    }

    int ru,rv;
    while(!q.empty()&&N>1){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        q.pop();

        ru=fp(u);
        rv=fp(v);
        if(ru==rv) continue;
        //cout << u << " " << v << " "<<   w << "\n";
        pa[rv]=ru;
        ans+=w;
        N--;
    }
    cout << ans;
}

