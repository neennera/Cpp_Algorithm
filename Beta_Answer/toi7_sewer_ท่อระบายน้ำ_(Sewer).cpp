#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

struct DATA{
    int x,y,w;
};

int N,M;
char m[105][105];
int x,y,nx,ny,w;
int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};
ll dp[102][102];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> m[i][j];
        }
    }

    queue <DATA> q;
    q.push({0,0,1});
    dp[0][0]=1;
    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        w=q.front().w;
        q.pop();

        if(dp[x][y]<w) continue;
        //cout << x+1 << " " << y+1 << "\n";
        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(dp[nx][ny]<w+1) continue;
            //cout << nx+1 << " " << ny+1 << "\n";
            if(i==0&& !(m[nx][ny]=='D'||m[nx][ny]=='B')) continue;
            if(i==1&& !(m[nx][ny]=='R'||m[nx][ny]=='B')) continue;
            if(i==2&& !(m[x][y]=='R'||m[x][y]=='B')) continue;
            if(i==3&& !(m[x][y]=='D'||m[x][y]=='B')) continue;

            if(dp[nx][ny]==w+1){
                cout << w+1 << "\n";
                cout << nx+1 << " " << ny+1 ;
                return 0;
            }

            dp[nx][ny]=w+1;
            q.push({nx,ny,w+1});
        }
    }
}
/*
2 2
1 1
1 2
1 1
1 1
*/

