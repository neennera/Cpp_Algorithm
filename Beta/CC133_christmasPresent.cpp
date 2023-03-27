#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M;
int a[105], b[105];
int ans=INT_MAX;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++)cin >> a[i];
    for(int i=0;i<M;i++)cin >> b[i];
    sort(a,a+N);
    sort(b,b+M);

    ans = min(ans,a[0]+b[0]+100); 
    if(N>1) ans = min(ans,a[0]+a[1]);
    if(M>1) ans = min(ans,b[0]+b[1]);

    cout << ans;
}