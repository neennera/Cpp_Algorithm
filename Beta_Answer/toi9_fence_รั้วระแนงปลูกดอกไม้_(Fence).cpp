#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,K,u,x,y;
ll dp[1005][1005];
ll ans=0,area;

int solve(){
    cin >> N >> M >> K;
    memset(dp,0,sizeof(dp));

    for(int i=0;i<K;i++){
        cin >> x >> y;
        dp[x+1][y+1]=1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+dp[i][j];
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    for(int K=min(N,M);K>=0;K--){
        for(int i=N;i-K>=0;i--){
            for(int j=M;j-K>=0;j--){
                int small=dp[i-1][j-1]-dp[i-K+1][j-1]-dp[i-1][j-K+1]+dp[i-K+1][j-K+1];
                int big=dp[i][j]-dp[i-K][j]-dp[i][j-K]+dp[i-K][j-K];

                if(big-small==0){
                    cout << K << "\n";
                    return 0;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    solve();
    solve();
    return 0;
}

