#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long

int N;
ll x[500005], y[500005];
ll ans = 0;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i];
    }
    sort(x,x+N);
    sort(y,y+N);

    for(int i=0;i<N;i++){
        int id = i+1;
        ans += (x[i+1]-x[i]) * id * (N-id);
        ans += (y[i+1]-y[i]) * id * (N-id);
    }
    cout << ans;
}
