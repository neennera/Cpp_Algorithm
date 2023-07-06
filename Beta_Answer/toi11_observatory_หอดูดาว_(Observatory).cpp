#include<bits/stdc++.h>
using namespace std;
#define ll long long

void USA(){
    freopen("div7.in","r", stdin);
    freopen("div7.out","w", stdout);
}

int N,M,K;
ll ans=LONG_MIN;
int TR[2002][2002]={0};
int a[2002][2002]={0};
int TL[2002][2002]={0};
int SQR[2002][2002]={0};
int SQL[2002][2002]={0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //input
    cin >> N >> M >> K;     //switch N,M for easy
    K--;
    int temp;
    for(short i=0;i<=N;i++){
        SQR[i][0]=0;
        TR[i][0]=0;
    }
    for(short j=0;j<=M;j++){
        SQR[0][j]=0;
        TR[0][j]=0;
    }
    for(short i=1;i<=N;i++){
        for(short j=1;j<=M;j++){
            cin >> temp;
            SQR[i][j]=SQR[i-1][j]+SQR[i][j-1]-SQR[i-1][j-1]+temp;
            TR[i][j]=TR[i-1][j-1]+SQR[i][j-1]-SQR[i-1][j-1]+temp;
            a[i][j]=temp;
        }
        for(short j=M;j>0;j--){
            SQL[i][j]=SQL[i-1][j]+SQL[i][j+1]-SQL[i-1][j+1]+a[i][j];
            TL[i][j]=TL[i-1][j+1]+SQL[i][j+1]-SQL[i-1][j+1]+a[i][j];
        }
    }
    /*
    cout << endl;
    for(short i=0;i<=N;i++){
        for(short j=0;j<=M;j++){
            cout << SQL[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    ll FS,SD;
    for(short i=1;i<=N-K;i++){
        for(short j=1;j<=M-K;j++){
            FS=TR[i+K][j+K]-TR[i-1][j-1]-SQR[i+K][j-1]+SQR[i-1][j-1];
            ans=max(ans,FS);
            SD=TL[i+K][j]-TL[i-1][j+K+1]-SQL[i+K][j+K+1]+SQL[i-1][j+K+1];
            //cout << SQL[i-1][j+K-1] << " ";
            ans=max(ans,SD);
        } //cout << endl;
    }
    cout << ans;
}
/*

3 3 2
1 1 2
3 3 3
1 1 2

7 8
4 6
*/

