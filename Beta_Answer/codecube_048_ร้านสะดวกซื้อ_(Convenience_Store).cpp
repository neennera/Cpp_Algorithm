#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,u,mod=1000007;
int dp[50005];
int a[505];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(dp,0,sizeof(dp));
    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> a[i];
    dp[0]=1;
    sort(a,a+N);
    for(int i=0;i<N;i++){
        for(int j=M;j>=0 && j-a[i]>=0;j--){
            if(dp[j-a[i]]){
                dp[j]+=dp[j-a[i]];
                dp[j]%=mod;
            }
        }
    }

    cout << dp[M];
}

