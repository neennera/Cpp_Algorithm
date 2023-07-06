#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>

int N;
char a[1010];
ll dp[1010][1010];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(dp,0,sizeof(dp));

    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];

    for(int c=1;c<N;c++){
        for(int i=0;i+c<N;i++){
            int j=i+c;
            if(a[i]==a[j])
                dp[i][j]=dp[i+1][j-1]+1;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][N-1];
}

