#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,K,u;
ll dp[1005][1005];
ll ans=0,area;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> u;
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+u;
        }
    }

    for(int i=K;i<=N;i++){
        for(int j=K;j<=M;j++){
            area=dp[i][j]-dp[i-K][j]-dp[i][j-K]+dp[i-K][j-K];
            ans=max(ans,area);
        }
    }

    cout << ans;
    return 0;
}

