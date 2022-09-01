#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,K,a[300002];
set <pii> s;
int ans=0;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> a[i];
        s.insert({a[i],i});
    }

    for(int i=N-1;i>=0;i--){
        int k=(*(s.lower_bound(make_pair(a[i]-K,0)))).sd;
        ans=max(ans,i-k);
        //cout << a[i] << " " << k << "\n";
    }
    cout << ans;
}
