#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,M,u,v;
string s;
vector <list<int>> path(300006);
int dp[300006]['Z'-'A'+1],ans=-1;
int dg[300006];

void solve(){
    queue <int> q;
    for(int i=1;i<=N;i++){
        if(dg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        u = q.front(); q.pop();
        //cout << u << " " << s[u] << " " << ans << "\n";
        
        for(int i=0;i<26;i++){
            ans=max(ans,dp[u][i]+((s[u]-'a')==i));
        }

        for(int v:path[u]){
            for(int i=0;i<26;i++){
                dp[v][i]=max(dp[v][i],dp[u][i]+((s[u]-'a')==i));
            }
            dg[v]--;
            if(dg[v]==0){
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0,sizeof(dp));
    cin >> N >> M;
    cin >> s;
    s = " "+s;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
        dg[v]++;
    }

    solve();

    for(int i=1;i<=N;i++){
        if(dg[i]>0){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}