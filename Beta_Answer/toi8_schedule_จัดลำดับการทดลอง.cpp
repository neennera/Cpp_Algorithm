#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>
#define db 0

int N,M;
int a[2][1003];
vector <vector<pii>> dp;

pii cal(int i,int j,int x,int id){
    pii c=dp[i][j];
    if(c.sd+a[x][id]<M){
        c.sd+=a[x][id];
        return c;
    }
    if(c.sd+a[x][id]==M){
        c.ft++;
        c.sd=0;
        return c;
    }
    c.ft++;
    c.sd=a[x][id];
    return c;
}

pii m(pii a,pii b){
    if(a.ft==b.ft){
        if(a.sd<=b.sd) return a;
        return b;
    }
    if(a.ft<b.ft) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> M >> N;
    for(int i=1;i<=N;i++) cin >> a[0][i]; //0
    for(int i=1;i<=N;i++) cin >> a[1][i]; //1

    //create dp
    dp.resize(N+2);
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++)
            dp[i].push_back({5005,5005});
    }

    //set up 0-0
    dp[0][0]={0,0};
    for(int i=1;i<=N;i++){
        dp[0][i]=cal(0,i-1,0,i);
        dp[i][0]=cal(i-1,0,1,i);
    }

    pii t1,t2,t3;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i>0&&j>0){
                t1=cal(i,j-1,0,j);
                t2=cal(i-1,j,1,i);
                dp[i-1][j-1]=cal(i-1,j-1,0,j);
                t3=cal(i-1,j-1,1,i);
                dp[i][j]=m(m(t1,t2),t3);
            }

            //cout << dp[i][j].ft << "," << dp[i][j].sd << " ";
        }
        //cout<< endl;
    }


    if(dp[N][N].sd==0)
        cout << dp[N][N].ft << "\n" << M;
    else
        cout << dp[N][N].ft+1 << "\n"<< dp[N][N].sd;
}

