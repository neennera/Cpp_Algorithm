#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define pb push_back

const int NX = 1e5 + 1;
int N,M,u,v;
vector<int> path1[NX], path2[NX];
stack <int> s;
bool vis[NX];

int ct = 0; // many of componant
int id[NX]; // node number of componant

void DFS(int u, int round, int num = 0) {
	vis[u] = true;

	vector<int> &path = (round == 1) ? path1[u] : path2[u]; // can use path[2][NX] too
	for (auto &v : path) {
		if (!vis[v]) DFS(v, round, num);
	}

	if (round == 1) s.push(u);      //push node
	if (round == 2) id[u] = num;    //set id not the lowlink
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for(int i=0;i<M;i++){
        cin >> u >> v;
		path1[u].pb(v);
		path2[v].pb(u);
	}

    //DFS1 : push node to stack
	for (int i=1;i<=N;i++) {
		if(!vis[i])
            DFS(i, 1);
	}

    //DFS2 : reverse graph, get node from stack
	memset(vis,0,sizeof(vis));
    while(!s.empty()){
        if(!vis[s.top()]) {
            ct++;
            DFS(s.top(), 2, ct);
        }
        s.pop();
    }

	cout << ct << "\n";
	for (int i=1;i<=N;i++){
        cout << id[i] << " ";
    }
}