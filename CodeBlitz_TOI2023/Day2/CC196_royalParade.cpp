#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int N,M,S,E,Q,ST,ED;
vector <list<pair<int,long>>>  path(100005);
ll depth[3][100005],w;
bool pass[100005];

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
        for(auto x:path[u]){
            if(depth[m][x.ft] <= depth[m][u]+ x.sd) continue;
            depth[m][x.ft]=depth[m][u]+ x.sd;
            q.push({-1*depth[m][x.ft],x.ft});
        }
    }
}

void walk2(int m){
    priority_queue <pair<ll,int>> q;
    q.push({0,ST});
    depth[m][ST] = 0;
    while(!q.empty()){
        
        u=q.top().sd;
        w=-1*q.top().ft;
        q.pop();
        //cout << u << "\n";
        if(u==ED){
            cout << w;
            exit(0);
        }
        if(depth[m][u]<w) continue;
        for(auto x:path[u]){
            //cout << depth[m][x.ft] << " " << depth[m][u]+ x.sd << " ; \n";
            if(depth[m][x.ft] <= depth[m][u]+ x.sd || pass[x.ft]) continue;
            depth[m][x.ft]=depth[m][u]+ x.sd;
            q.push({-1*depth[m][x.ft],x.ft});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    memset(depth,0x3f,sizeof(depth));
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w});
        path[v].push_back({u,w});
    }
    cin >> S >> E >> ST >> ED;
    walk(S,E,0);
    walk(E,S,1);

    //find a shortest path that royal go to
    for(int i=1;i<=N;i++){
        //cout << depth[0][i]+depth[1][i] << " ";
        if(depth[0][i]+depth[1][i]==depth[0][E]){
            pass[i]=1;
            //cout << i << " ";
        }
        
    }

    //DFS without a royal
    walk2(2);
    cout << -1;
}