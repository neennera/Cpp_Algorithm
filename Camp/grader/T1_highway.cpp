#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define MAX 100005

int N,M,u,v,Q;
vector <list<int>> path(MAX);
bitset <MAX> close;
bool vis[MAX];
int in[MAX];

void DFS(int u){
    if(vis[u] || close[u]) return;
    vis[u]=1;

    for(auto v:path[u]){
        if(!vis[v] && !close[v])
            DFS(v);
    }  
}

bool check(int u){
    if(close[u]==1 || in[u]==0) return 1;
    return 0;
}

void closing(int u){
    close[u]=1;
    for(auto v:path[u]){
        in[v]--;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(in,0,sizeof(in));

    cin >> N >> M >> Q;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
        in[v]++;
    }

    while(Q--){
        cin >> v;
        if(v==1){
            cin >> u;
            closing(u);
        }else{
            cin >> u;
            if(check(u)){
                cout << "0\n";
            }else{
                memset(vis,0,sizeof(vis));
                DFS(1);
                if(vis[N] && vis[u]){cout << "1\n";}
                else{cout << "0\n";}
            }            
        }
    }

    return 0;
}