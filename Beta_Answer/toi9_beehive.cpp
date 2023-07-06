#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int N,M;
int a[1005][1005];
ll dp[1005][1005][2];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0,sizeof(dp));
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==1){ cin >> dp[i][j][0]; dp[i][j][1]=1;}
            else cin >> a[i][j];
        }
    }
    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i%2==0){
                if(dp[i-1][j+1][0]==dp[i-1][j][0]){
                    dp[i][j][0]=dp[i-1][j+1][0] +a[i][j];
                    dp[i][j][1]=dp[i-1][j+1][1] +dp[i-1][j][1];
                }
                else{
                    if(dp[i-1][j+1][0]>dp[i-1][j][0]){
                        dp[i][j][0]=dp[i-1][j+1][0] +a[i][j];
                        dp[i][j][1]=dp[i-1][j+1][1];
                    }else{
                        dp[i][j][0]=dp[i-1][j][0] +a[i][j];
                        dp[i][j][1]=dp[i-1][j][1];
                    }
                }
            }
            if(i%2==1){
                if(dp[i-1][j-1][0]==dp[i-1][j][0]){
                    dp[i][j][0]=dp[i-1][j-1][0] +a[i][j];
                    dp[i][j][1]=dp[i-1][j-1][1] +dp[i-1][j][1];
                }
                else{
                    if(dp[i-1][j-1][0]>dp[i-1][j][0]){
                        dp[i][j][0]=dp[i-1][j-1][0] +a[i][j];
                        dp[i][j][1]=dp[i-1][j-1][1];
                    }else{
                        dp[i][j][0]=dp[i-1][j][0] +a[i][j];
                        dp[i][j][1]=dp[i-1][j][1];
                    }
                }
                //dp[i][j]= max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
            }
        }
    }
    ll ans=INT_MIN, ct=0;
    for(int j=1;j<=M;j++){
        if(dp[N][j][0]==ans){ ct+=dp[N][j][1];}
        if(dp[N][j][0]>ans){
            ans=dp[N][j][0];
            ct=dp[N][j][1];
        }
    }
    cout << ans << " " << ct;
}
