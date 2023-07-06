#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 0

int N,M,K;
int dp[10005];
vector <list<int>> path(10005);
int u,v;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >>  K >> N >> M;
    fill(dp,dp+N+5,INT_MAX);
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
    }

    int m,mx=1;
    queue <pii> q;
    q.push({1,1});
    dp[1]=1;
    while(!q.empty()){
        u=q.front().ft;
        m=q.front().sd;
        q.pop();

        if(dp[u]<m) continue;
        mx=max(mx,u);

        //cout << u << "\n";
        if(m>K) continue;

        for(auto v:path[u]){
            if(dp[v]>m+1){
                dp[v]=m+1;
                q.push({v,m+1});
            }
        }
    }

    cout << mx;
}

