#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 1
struct DATA{
    int x,y,w,s;
    bool operator < (const DATA & d2) const{
        if(w==d2.w) return __builtin_popcount(s) < __builtin_popcount(d2.s);
        return w>d2.w;
    }
};
int N, M;
ll dp[502][502][8];
char m[502][502];
queue <DATA> q;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            m[i][j]=s[j];
            if(s[j]=='S') q.push({i,j,0,0});
            for(int k=0;k<8;k++) dp[i][j][k]=INT_MAX;
        }
    }
    int x,y,w,s;
    int nx,ny;
    int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};
    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        w=q.front().w;
        s=q.front().s;
        q.pop();
        //cout << x << "  "<< y << "\n";
        if(dp[x][y][s]!=INT_MAX) continue;
        dp[x][y][s]=w;

        switch(m[x][y]){
            case 'j' : s|=(1); break;
            case 'b' : s|=(2); break;
            case 'p' : s|=(4); break;
            default : break;
        }
        for(int i=0;i<4;i++){
            nx=x+wx[i], ny=y+wy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(dp[nx][ny][s]!=INT_MAX||m[nx][ny]=='#') continue;
            if(m[nx][ny]=='J'&&((s&1)==0)) continue;
            if(m[nx][ny]=='B'&&((s&2)==0)) continue;
            if(m[nx][ny]=='P'&&((s&4)==0)) continue;
            if(m[nx][ny]=='E'){
                cout << w+1; return 0;
            }
            q.push({nx,ny,w+1,s});
        }
    }
    cout << "-1";
}
/*
2 3
SjJ
JJE
*/


