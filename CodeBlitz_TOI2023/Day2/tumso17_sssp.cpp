#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

ll N,M;
int u,v,w,S,E;
int pa[100005]; 

vector <double> depth(100005, DBL_MAX);
vector<vector<pair<int, double>>> path(100005);
priority_queue <pair<double, int>> pq;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> S >> E;
    for (int i=0;i<M;i++)    {
        cin >> u >> v >> w;
        path[u].push_back({v, log10(w)});
        path[v].push_back({u, log10(w)});
    }

    pq.push({0, S});
    pa[S]=S;
    depth[S]=0;

    while (!pq.empty()){
        double w=-1*pq.top().first;
        int u=pq.top().second;
        pq.pop();

        for(auto x:path[u]){
            int v=x.first;
            double ww=x.second;
            if (w+ww<depth[v]){
                depth[v]=w+ww;
                pa[v]=u;
                pq.push({-1 * (w+ww), v});
            }
        }
    }

    stack <int> ans;
    int temp=E;
    while (pa[temp]!=temp){ //will stop at S
        ans.push(temp);
        temp=pa[temp];
    }

    ans.push(S);
    
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
}