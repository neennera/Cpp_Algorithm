#include<bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(int i=s;i<e;i++)

char a[25][25];
int N,M,u;
int block[25];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N >> M;
    fill(block,block+25,N);
    f(i,0,N){
        f(j,0,M){
            cin >> a[i][j];
            if(a[i][j]=='O')
                block[j]=min(block[j],i);
        }
    }
    f(i,0,M){
        cin >> u;
        for(int j=block[i]-1;j>=0&&u>0;j--,u--){
            a[j][i]='#';
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}

