#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,M,K,L;
int a[1000006];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K >> L;
    for(int i=0;i<N;i++) cin >> a[i];

    while(K--){
        int i=0; ll ans=0;
        int u;
        for(int j=0;j<M;j++){
            cin >> u;
            if(i==N) continue;
            while(i<N&&a[i]<u-L) i++;
            while(i<N&&a[i]<=u+L){
                i++; ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
10 2
5 7
2 4
B
*/


