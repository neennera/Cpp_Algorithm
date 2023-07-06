#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
struct DATA{ int v,w; };

int N,M,O,i,j;
ll dp[53][53];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(dp,0,sizeof(dp));
    cin >> N >> M >> O;
    for(int k=0;k<O;k++){
        cin >> i >> j;
        dp[i][j]=INT_MIN;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(dp[i][j]==INT_MIN) dp[i][j]=0;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            if(i==1&&j==1) dp[i][j]=1;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[N][M];

}

