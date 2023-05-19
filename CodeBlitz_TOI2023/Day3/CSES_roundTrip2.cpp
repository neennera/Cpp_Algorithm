#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
 
int N,M,u,v,ct;
vector <list<int>> path(100005);
bitset <100005> vis;
bitset <100005> in;
stack <int> s;
 
void DFS(int u,int pa){
    if(vis[u]) return;
    vis[u]=1;
    in[u]=1, ct++;
    s.push(u);
 
    for(auto v:path[u]){
        if(in[v]&&ct>1){
            vector <int> ans;
            ans.push_back(v);
            while(s.top()!=v){
                ans.push_back(s.top());
                s.pop();
            }
            ans.push_back(v);
            int n=ans.size();
            cout << n << "\n";
            for(int i=n-1;i>=0;i--){
                cout << ans[i] << " ";
            }
            exit(0);
        }
 
        DFS(v,u);
    }
 
    s.pop();
    in[u]=0, ct--;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
    }
 
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        ct=0;
        DFS(i,-1);
    }
 
    cout << "IMPOSSIBLE";
}