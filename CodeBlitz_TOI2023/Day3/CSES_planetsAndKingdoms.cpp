#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define pb push_back
 
const int NX = 1e5 + 1;
int N,M,u,v;
vector<int> path[NX];
stack <int> s;
bool vis[NX];
 
int ct = 0; // many of componant
int ids = 1; // assign disc
int disc[NX], lowlink[NX]; // node number of componant
bool onStack[NX]; //check if u is in the stack
 
void DFS(int u) {
	vis[u] = true;
    onStack[u] = true;
    disc[u] = lowlink[u] = ids++;
    s.push(u);
 
    //check all neighbor
	for (auto v : path[u]) {
		if (!vis[v]) DFS(v);
        if (onStack[v]) lowlink[u]=min(lowlink[u],lowlink[v]);
	}
 
    //if we are low link of SCC
    if(disc[u]==lowlink[u]){
        ct++;
        while(!s.empty()){
            int temp=s.top(); s.pop();
            onStack[temp]=0;
            //lowlink[temp]=u;
            lowlink[temp]=ct;
            if(temp==u) break;
        }
    }
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
 
	cin >> N >> M;
	for(int i=0;i<M;i++){
        cin >> u >> v;
		path[u].pb(v);
	}
     
	for(int i=1;i<=N;i++) {
		if(!vis[i])
            DFS(i);
	}
 
	cout << ct << "\n";
	for(int i=1;i<=N;i++){
        cout << lowlink[i] << " ";
    }
}