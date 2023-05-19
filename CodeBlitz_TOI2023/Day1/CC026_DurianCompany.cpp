#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 1
int N,a,b,mm=0;
ll sd=0;
int m[1000006];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    memset(m,0,sizeof(m));
    for(int i=0;i<N;i++){
        cin >> a >> b;
        m[a]++;
        m[b]--;
        mm=max(mm,b);
    }
    ll ans=0;
    for(int i=0;i<=mm+5;i++){
        sd+=m[i];
        ans=max(ans,sd);
    }
    cout << ans;
    return 0;
}
