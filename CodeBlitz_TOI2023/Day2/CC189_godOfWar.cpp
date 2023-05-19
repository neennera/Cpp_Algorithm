#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,S,E,Q;
vector <list<pair<int,long>>>  path(100005);
ll depth[2][100005],w, sum=0, ans=0;

int u,v;
void DFS(int st,int m){
    priority_queue <pair<ll,int>> q;
    depth[m][st]=0;
    q.push({0,st});
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
        sum += w;
    }

    DFS(S,0);
    DFS(E,1);
    
    //delete all except the path to u and v
    for(int u=0;u<N;u++){
        for(auto x:path[u]){
            // cout << u << " " << x.ft <<  " : " << sum - (depth[0][u]+depth[1][x.ft]) << "\n";
            ans = max(ans, sum - (depth[0][u]+depth[1][x.ft]));
        }
    }
    
    cout << ans;
}