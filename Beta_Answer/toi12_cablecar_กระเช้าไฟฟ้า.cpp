#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,ll>
#define db 0

ll N,M,u,v,w,st,ed,n,K;
vector <pii> path[2505];
ll dist[2505];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(dist,0x3f,sizeof(dist));
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        path[u].push_back({v,w-1});
        path[v].push_back({u,w-1});
    }
    cin >> st >> ed >> K;
    dist[st]=0;
    priority_queue <pii> q;
    q.push({0,st});
    while(!q.empty()){
        u=q.top().sd;
        n=-1*q.top().ft;
        q.pop();


        if(dist[u]<n) continue;

        for(auto [v,ww]:path[u]){
                ll temp;
            if(K%ww==0){
                temp=max(n,(ll)((K)/ww));
            }else{
                temp=max(n,(ll)((K+ww)/ww));
            }

            if(dist[v]>temp){
                dist[v]=temp;
                q.push({-1*temp,v});
            }
        }
    }

    cout << dist[ed];
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 2 60
*/

