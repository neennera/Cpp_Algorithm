#include<bits/stdc++.h>
using namespace std;

void USA(){
    freopen("div7.in","r", stdin);
    freopen("div7.out","w", stdout);
}

struct DATA{
    int x,y,t;
};

int N,M;
int vis[101][101]={0};
char sew[101][101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> sew[i][j];
        }
    }
    queue <DATA> q;
    q.push({0,0,1});
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int t=q.front().t;
        q.pop();
        if(vis[x][y]==t){
            cout << t << endl;
            cout << x+1 << " " << y+1;
            return 0;
        }
        vis[x][y]=t;
        if((sew[x][y]=='R'||sew[x][y]=='B')&&(y+1<M)&&(vis[x][y+1]==0)){
            q.push({x,y+1,t+1});
        }
        if((sew[x][y]=='D'||sew[x][y]=='B')&&(x+1<N)&&(vis[x+1][y]==0)){
            q.push({x+1,y,t+1});
        }
        if((sew[x][y-1]=='R'||sew[x][y-1]=='B')&&(y-1>=0)&&(vis[x][y-1]==0)){
            q.push({x,y-1,t+1});
        }
        if((sew[x-1][y]=='D'||sew[x-1][y]=='B')&&(x-1>=0)&&(vis[x-1][y]==0)){
            q.push({x-1,y,t+1});
        }
    }
}

