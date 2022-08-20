#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd socind
#define pii pair<int,int>

int N[2], M[2];
int u,v,w;
bitset <2005> dp[2][1005];
int dg[2][1005]={0};
vector <int> path[2][1005];
vector <int> back[2][1005];

void solve(int d){
    for(int i=0;i<M[d];i++){
        cin >> u >> v;
        path[d][u].push_back(v);
        back[d][v].push_back(u);
        dg[d][v]++;
    }

    //init topo queue
    queue <int> q;
    for(int i=0;i<=N[d];i++)
        if(dg[d][i]==0)
            q.push(i);
    //dp[d][1][0]=1;

    //topo sort
    while(!q.empty()){
        u=q.front();
        q.pop();

        if(back[d][u].empty()) dp[d][u][0]=1;
        for(auto pa:back[d][u]){
            dp[d][u] |= dp[d][pa]<<1; //add one more step
        }

        for(auto v:path[d][u]){
            dg[d][v]--;
            if(dg[d][v]==0)
                q.push(v);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dg,0,sizeof(dg));
    cin >> N[0] >> N[1];
    cin >> M[0] >> M[1];

    solve(0);
    solve(1);

    bitset <2005> ans;
    
    for(int i=0;i<=N[0];i++) cout << dp[0][N[0]][i];
    for(int i=0;i<=N[1];i++) cout << dp[1][N[1]][i];

    for(int i=0;i<=1000;i++){
        if(dp[0][N[0]][i]){
            ans|=dp[1][N[1]]<<1;
            //if {1} has a so... {sum} has {2} + a
        }
    }
    int Q,k;
    cin >> Q;
    while(Q--){
        cin >> k;
        if(ans[k]){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}