#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,Q,a,b,c;
ll dp[200005],ans=0;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0,sizeof(dp));

    cin >> N >> Q;
    while(Q--){
        cin >> a >> b >> c;
        ll up=0,down=0;
        for(int i=1;i<=N;i++){
            up= max (up,dp[i] - abs(i-a));
            down =max (down , dp[i] - abs(i-b));
        }
        dp[b] = max(dp[b], up + c);
        dp[a] = max(dp[a], down + c);
        ans=max(ans, max(dp[a],dp[b]));
        cout << ans << "\n";
    }

    

    return 0;
}