#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

struct DATA{
    int u;
    ll w;
    bool c;
    bool operator < (const DATA & d2) const{
        return w>d2.w;
    }
};

int N,M,K,T;
int u,v;
bool c;
ll w;
ll dp[2][100005],ans=LONG_MAX;
vector <pair<int,int>> path[100005];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    cin >> N >> M >> K >> T;
    for(int i=0;i<M;i++){
        cin >> u >>v >> w;
        path[u].push_back({v,w});
        path[v].push_back({u,w});
    }

    dp[0][1]=0;
    dp[1][1]=0;
    priority_queue <DATA> q;
    q.push({1,0,0});
    while(!q.empty()){
        u=q.top().u;
        w=q.top().w;
        c=q.top().c;
        q.pop();

        if(dp[c][u] < w) continue;
        ll ww;

        //cout <<"\n"<< u << "\n";
        for(int i=0;i<path[u].size();i++){

            v=path[u][i].ft;
            ww=path[u][i].sd;
            //cout << "   " << dp[0][v] << " ";
            if(c){
                if(dp[1][v] > dp[1][u] + ww){
                    dp[1][v]=dp[1][u] + ww;
                    q.push({v,dp[1][v],1});

                }
            }else{
                if(dp[0][v]>dp[0][u]+ww){
                    dp[0][v]=dp[0][u]+ww;
                    q.push({v,dp[0][v],0});
                }
                if(dp[1][v]>dp[0][u]+K){
                    dp[1][v]=dp[0][u]+K;
                    q.push({v,dp[1][v],1});
                }
            }
        }
    }

    if(min(dp[0][N],dp[1][N])>T){cout << "No Honey TT";}
    else{cout << "Happy Winnie the Pooh :3\n" << min(dp[0][N],dp[1][N]);}
}

