#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<double,int>
#define db 0

int N,K;
pii dot[15005];
ll dp[15005];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> dot[i].ft >> dot[i].sd;
        dp[i]=1e17;
    }
    dp[0]=0;
    ll temp;
    for(int i=1;i<N;i++){
        ll mm=1e17;
        int id=-1;
        for(int j=i;j<N;j++){
            temp=abs(dot[i-1].ft-dot[j].ft)+abs(dot[i-1].sd-dot[j].sd);
            //cout << temp << " " << dp[id] << "\n";
            dp[j]=min(dp[j],temp);
            if(dp[j]<mm){
                mm=dp[j], id=j;
            }
        }
        swap(dot[i],dot[id]);
        swap(dp[i],dp[id]);
    }
    sort(dp,dp+N);
    ll ans=0;
    for(int i=1;i<=N-K;i++){
        //cout << dp[i] << " ";
        ans+=dp[i];
    }

    cout << ans;
}

