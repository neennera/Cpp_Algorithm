#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

struct DATA{
    int x,y;
    ll n;
};

int N,M;
int x,y,nx,ny;
ll n;
int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};

char a[2005][2005];
bool dp[2005][2005];
queue <DATA> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));

    cin >> N >> M;
    int K=0;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            a[i][j]=s[j];
            if(s[j]=='X'){
                q.push({i,j,0});
                dp[i][j]=1;
            }

            if(s[j]=='A'){
                K++;
            }

        }
    }

    ll ans=0;
    int k=K;

    while(!q.empty()&&K){
        x=q.front().x;
        y=q.front().y;
        n=q.front().n;
        q.pop();

        //cout << a[x][y] << "\n";
        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(a[nx][ny]=='W'||dp[nx][ny]) continue;
            dp[nx][ny]=1;
            q.push({nx,ny,n+1});
            if(a[nx][ny]=='A'){
                ans+=(n+1)*2;
                K--;
            }
        }
    }
    cout << k-K << " " << ans;
}

