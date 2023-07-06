#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,K,M,u;
ll a[300][300];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> a[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ll temp=0;
            temp+=a[i][j];
            for(int ii=max(0,i-K);ii<=min(N-1,i+K);ii++){
                if(i==ii) continue;
                if(abs(i-ii)%2==0){
                    temp+=a[ii][j];
                }else{
                    temp-=a[ii][j];
                }
            }

            for(int jj=max(0,j-K);jj<=min(M-1,j+K);jj++){
                if(j==jj) continue;
                if(abs(j-jj)%2==0){
                    temp+=a[i][jj];
                }else{
                    temp-=a[i][jj];
                }
            }
            ans=max(ans,temp);
        }
    }

    cout << ans;
}

