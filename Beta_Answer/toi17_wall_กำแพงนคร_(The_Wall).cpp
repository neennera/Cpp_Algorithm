#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,M;
char m[1002][1002];
ll ans=0;
bool vis[1002][1002];


int x,y,nx,ny,w;
int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};

int DFS_W(int u,int v){
    queue <pii> q;
    q.push({u,v});
    vis[u][v]=1;

    while(!q.empty()){
        x=q.front().ft;
        y=q.front().sd;
        q.pop();

        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=M||vis[nx][ny]||m[nx][ny]!='.') continue;

            vis[nx][ny]=1;
            m[nx][ny]='0';
            q.push({nx,ny});
        }
    }
}

ll DFS(int u,int v){
    ll ct=0;
    queue <pii> q;
    q.push({u,v});
    vis[u][v]=1;

    while(!q.empty()){
        x=q.front().ft;
        y=q.front().sd;
        q.pop();

        ct+=4;

        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(m[nx][ny]=='X'||m[nx][ny]=='.') ct--;
            if(m[nx][ny]!='X') continue;

            if(vis[nx][ny]) continue;
            vis[nx][ny]=1;
            q.push({nx,ny});
        }
    }

    return ct;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> m[i];
    }

    //memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));

    //if flood change '.' -> '0'
    DFS_W(0,0);

    //wall
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(m[i][j]=='X'&& !vis[i][j]){
                //cout << i << " " << j << "\n";
                ans=max(ans,DFS(i,j));
            }
        }
    }

    cout << ans;
}
/*
2 2
1 1
1 2
1 1
1 1
*/

