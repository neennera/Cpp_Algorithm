#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N,M,u,v;
vector <vector <int>> path, rpath;
vector <int> todo, comps, comp;
//comp = lowlink of each node
//comps = all lowlink id
vector <bool> vis;

void dfs(int x) {
	vis[x] = 1;
	for(auto y: path[x]){
		if (!vis[y])
			dfs(y);
	}
	//push after visit all neighbour
	todo.push_back(x);
}

void dfs2(int x, int v) {
	comp[x] = v;
	for(auto y:rpath[x]){
		if(comp[y] == -1)
			dfs2(y, v);
	}
}

void gen(int N) {  // fills allComp
	for(int i=1;i<=N;i++){
		if(!vis[i])
			dfs(i);
	}
	reverse(begin(todo), end(todo));
	for(auto x: todo){
		if (comp[x] == -1) {
			dfs2(x, x);
			comps.push_back(x);
		}
	}
}


int value[100005];  // value of each room
ll group[100005];   // value in each SCC
vector <int> rgraph[100005];  // reverse graph
ll dp[100005];


ll DP(int i) {
	if (dp[i]) return dp[i];

	dp[i] = group[i];   //coin in group
    for(auto j : rgraph[i]){    //coin from around node
        dp[i] = max(dp[i], DP(j) + group[i]);
    }
	return dp[i];
}

int main() {
	ios_base::sync_with_stdio(0),cin.tie(0);

	cin >> N >> M;
	path.resize(N+1), rpath.resize(N+1), vis.resize(N+1);
	comp = vector <int> (N+1, -1);

	for(int i=1;i<=N;i++){
        cin >> value[i];
    }
	while(M--){
		cin >> u >> v;
		path[u].push_back(v);
		rpath[v].push_back(u);
	}
	
	// generate SCC using Kasaraju's but use vector instand of stack
	gen(N);

	// sum value for each SCC
	for(int i=1;i<=N;i++){
        group[comp[i]] += value[i];
    }

	// create reverse edges for SCC
	for(int i=1;i<=N;i++){
        for(auto j : path[i]) {
            if (comp[i] == comp[j]) continue;
            rgraph[comp[j]].push_back(comp[i]);
        }
    } 

	// find dp value for each SCC
	ll ans = 0;
	for(auto i : comps){
        ans = max(ans, DP(i));
    }

	cout << ans << '\n';
}