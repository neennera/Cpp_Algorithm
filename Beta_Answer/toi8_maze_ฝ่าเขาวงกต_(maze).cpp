#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pq q.top()
#define qq q.front()
struct DATA{
    int x,y;
    ll n;
};

int N,M;
int x,y,nx,ny,s;
int edx,edy;
ll n;
int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};

int m[155][155];
bool vis[155][155][2];
ll dp[155][155][2];
stack <DATA> q;

void DFS(int x,int y,int s){
    q.push({x,y,1});
    dp[x][y][s]=1;
    while(!q.empty()){
        x=pq.x;
        y=pq.y;
        n=pq.n;
        q.pop();

        if(dp[x][y][s]<n) continue;

        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(dp[nx][ny][s]>n+1){
                dp[nx][ny][s]=n+1;
                vis[nx][ny][s]=1;
                if(m[nx][ny]==1){
                    q.push({nx,ny,n+1});
                }
            }

        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    //*******************
    memset(m,0,sizeof(m));
    memset(dp,0x3f,sizeof(dp));
    memset(vis,0,sizeof(vis));

    cin >> N >> M;
    cin >> x >> y;
    x--,y--;
    cin >> edx >> edy;
    edx--, edy--;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> m[i][j];
        }
    }

    if(x==edx&&y==edy){
        cout << "1\n1"; return 0;
    }

    //********************

    DFS(x,y,0);
    DFS(edx,edy,1);

    //*******************
    ll ans=LLONG_MAX, ct=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(vis[i][j][0]&&vis[i][j][1]){
                ct++;
                ans=min(ans,dp[i][j][0]+dp[i][j][1]-1);
            }
    }

    }
    cout << ct << "\n" << ans;
}
/*
2 2
1 1
1 2
1 1
1 1
*/

