#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int N,M,S,E,Q;
vector <list<pair<int,long>>>  path(200005);
ll depth[3][200005],w;
int u,v;
void walk(int st,int ed,int m){
    priority_queue <pair<ll,int>> q;
    depth[m][st]=0;
    q.push({0,st});
    while(!q.empty()){
        u=q.top().sd;
        w=-1*q.top().ft;
        q.pop();
        if(depth[m][u]<w) continue;
        if(m<2&&u==ed) break;
        for(auto x:path[u]){
            if(depth[m][x.ft] <= depth[m][u]+ x.sd) continue;
            depth[m][x.ft]=depth[m][u]+ x.sd;
            q.push({-1*depth[m][x.ft],x.ft});
        }
    }
}
void walk2(set <int> s,int m){
    priority_queue <pair<ll,int>> q;
    for(auto st:s){ depth[m][st]=0;  q.push({0,st});}
    while(!q.empty()){
        u=q.top().sd;
        w=-1*q.top().ft;
        q.pop();
        if(depth[m][u]<w) continue;
        for(auto x:path[u]){
            if(depth[m][x.ft] <= depth[m][u]+ x.sd) continue;
            depth[m][x.ft]=depth[m][u]+ x.sd;
            q.push({-1*depth[m][x.ft],x.ft});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> S >> E;
    memset(depth,0x3f,sizeof(depth));
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
        path[v].push_back({u,w});
    }
    walk(S,E,0);
    walk(E,S,1);
    set <int> s;
    for(int i=1;i<=N;i++){
        if(depth[0][i]+depth[1][i]==depth[0][E]){
            s.insert(i);
        }
    }
    walk2(s,2);
    cin >> Q;
    for(int i=0;i<Q;i++){
        cin >> u;
        cout << depth[2][u] << endl;
    }
}