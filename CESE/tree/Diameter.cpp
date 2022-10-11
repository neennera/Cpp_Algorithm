#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,u,v,ans = 0;
vector <list<int>> path(200005);

int solve(int u,int pa){
    priority_queue <int> pq;
    pq.push(0), pq.push(0);
    for(auto v:path[u]){
        if(v==pa) continue;
        pq.push(solve(v,u));
    }
    int a=pq.top(); pq.pop();
    int b=pq.top(); pq.pop();
    ans=max(ans, a+b);
    return a + 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    solve(1,-1);
    cout << ans;
}