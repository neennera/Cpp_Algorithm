#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,M;
int m[22][22];
int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};
int x,y,nx,ny;
stack <pii> s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    cin >> x >> y;
    s.push({y-1,x-1});
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> m[i][j];
        }
    }

    int mx=m[y-1][x-1];

    while(!s.empty()){
        x=s.top().ft;
        y=s.top().sd;
        s.pop();

        if(m[x][y]==100) continue;

       //cout << x << " " << y << "\n";
        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=N) continue;
            if(m[nx][ny]==100||m[nx][ny]<=m[x][y]) continue;
            mx=max(mx,m[nx][ny]);
            //m[nx][ny]=100;
            s.push({nx,ny});
        }
        m[x][y]=100;
    }

    cout << mx;
}


