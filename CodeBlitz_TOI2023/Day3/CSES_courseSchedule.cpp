#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
 
int N,M,ct,u;
vector <list<int>> path(100005);
int order[100005];
queue <int> ans;
bitset <100005> vis;
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> N >> M;
    ct=N;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        path[a].push_back(b);
        order[b]++;
    }
    for(int i=1;i<=N;i++){
        if(order[i]!=0 || vis[i]){
            continue;
        }
 
        queue <int> q;
        q.push(i);
        while(!q.empty()){
            u=q.front();
            q.pop();
            ans.push(u);
            vis[u]=1;
            ct--;
            for(auto v:path[u]){
                if(--order[v]==0 && !vis[v]){
                    q.push(v);
                }
            }
        }
    }
 
    
 
    if(ct!=0){
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
}