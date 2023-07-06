#include<bits/stdc++.h>
using namespace std;

int N, a[20][20],ans=0,aa[20][20];
int wx[]={-1,0,0,1}, wy[]={0,-1,1,0};

int walk(int i,int j,int c){
    if(i<0||i>=N||j<0||j>=N) return 0;
    if(aa[i][j]==-1||a[i][j]!=c) return 0;
    int n=1;
    aa[i][j]=-1;
    for(int k=0;k<4;k++){
        if(i+wx[k]<0||i+wx[k]>=N||j+wy[k]<0||j+wy[k]>=N) continue;
        if(aa[i+wx[k]][j+wy[k]]==-1||a[i+wx[k]][j+wy[k]]!=c) continue;
        n+=walk(i+wx[k],j+wy[k],c);
    }
    return n;
}

void pf(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << aa[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int flood(int i,int j){
    int n=walk(i,j,a[i][j]);

    if(n>3||n<3) return 0;
    if((a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2])&&(j+2<N)) return 0;
    if((a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j])&&(i+2<N)) return 0;

    //pf();
    ans++;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N;
    memset(aa,0,sizeof(aa));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(aa[i][j]==-1) continue;
            flood(i,j);
        }
    }
    cout << ans;
}

