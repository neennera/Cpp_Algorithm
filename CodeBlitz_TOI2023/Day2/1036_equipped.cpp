#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>

int N,K,c,k;
ll dp[(1<<8)],u;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0x3f,sizeof(dp));

    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> u;
        c=0;
        for(int j=0;j<K;j++){
            cin >> k;
            if(!k) continue;
            c|=(1<<j);
        }
        dp[c]=min(dp[c],u);
    }
    
    for(int i=1;i<(1<<K);i++){
        for(int j=1;j<(1<<K);j++){
            dp[i|j]=min(dp[i|j],dp[i]+dp[j]);
        }
    }

    cout << dp[(1<<K)-1];
}