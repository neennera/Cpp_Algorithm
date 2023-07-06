#include<bits/stdc++.h>
using namespace std;

set <pair<int,int>> s;
int i,j,N,ans=0;
bool a[1005][1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(a,0,sizeof(a));
    int I=INT_MIN, J=INT_MIN;

    while(N--){
        cin >> i >> j;
        a[i][j]=1;
        I=max(i,I); J=max(j,J);
    }

    for(int i=0;i<=I;i++){
        for(int j=0;j<=J;j++){
            if(a[i][j]) ans++;
        }
    }

    cout << ans;
}

