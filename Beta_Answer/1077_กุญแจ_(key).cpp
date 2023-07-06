#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int N,M,i,j,k;
set <pair<int,int>> s;
int ps[1005][1005];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(ps,0,sizeof(ps));
    cin >> N >> M;
    int Mi=0,Mj=0;
    for(int l=0;l<N;l++){
        cin >> i >> j;
        Mi=max(Mi,i+1);
        Mj=max(Mj,j+1);
        ps[i+1][j+1]++;
    }
    for(int i=1;i<=Mi;i++){
        for(int j=1;j<=Mj;j++){
            ps[i][j]=ps[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            //cout << ps[i][j] << " ";
        }
        //cout << endl;
    }
    while(M--){
        cin >> i >> j >> k;
        i++,j++;
        //out << min(i+k,Mi+1) << " " << min(j+k,N+1) << endl;
        int p= ps[min(i+k,Mi)][min(j+k,Mj)] - ps[max(0,i-k-1)][min(j+k,Mj)] - ps[min(i+k,Mi)][max(0,j-k-1)] + ps[max(0,i-k-1)][max(0,j-k-1)];
        cout << p << "\n";
    }
}

