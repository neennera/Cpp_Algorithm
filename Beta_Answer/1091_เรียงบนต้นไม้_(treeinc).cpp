#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
const int MAX_N=300003;

int N,u,v;
vector <int> path[MAX_N];
bool vis[MAX_N];
ll Inc[MAX_N], Dec[MAX_N];
ll ans=0;

void DFS(int u){
    if(vis[u]) return;
    vis[u]=1, Inc[u]=1, Dec[u]=1;

    for(auto v:path[u]){
        if(!vis[v]) DFS(v);

        if(v<u){            
            Inc[u]=max(Inc[u], Inc[v]+1);
        }else{
            Dec[u]=max(Dec[u], Dec[v]+1);
        }
    }    
    
    ans = max (ans, max( max(Inc[u], Dec[u]) , Inc[u]+Dec[u]-1) );
}

void sol1(){
    DFS(1);
}

void sol2(){
    for(int u=1;u<=N;u++){
        if(vis[u]) continue;
        vis[u]=1; Inc[u]=1;
        for(auto v:path[u]){
            if(v>=u) continue;
            Inc[u] = max(Inc[u], Inc[v]+1);
        }
        ans = max(ans, Inc[u]);   
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(vis,0,sizeof(vis));
    memset(Inc,0,sizeof(Inc));
    memset(Dec,0,sizeof(Dec));

    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    sol1(); //sol 1 : consider incress node and decress node        
    //sol2(); //sol 2 : consider only incress node

    cout << ans;
}
