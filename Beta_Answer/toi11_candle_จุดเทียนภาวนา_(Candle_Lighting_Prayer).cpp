#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int N,M;
bool a[2005][2005];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(a,0,sizeof(a));
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            a[i][j]=s[j]-'0';
        }
    }
    int x,y,nx,ny,ct=0;
    int wx[]={-1,-1,-1,0,0,1,1,1}, wy[]={-1,0,1,-1,1,-1,0,1};
    queue <pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!a[i][j]) continue;
            q.push({i,j});
            a[i][j]=0;
            ct++;
            while(!q.empty()){
                x=q.front().ft;
                y=q.front().sd;
                q.pop();
                for(int i=0;i<8;i++){
                    nx=x+wx[i], ny=y+wy[i];
                    if(nx<0||nx>=N||ny<0||ny>=M) continue;
                    if(!a[nx][ny]) continue;
                    a[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << ct;
}

