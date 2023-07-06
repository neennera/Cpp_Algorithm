#include<bits/stdc++.h>
using namespace std;

long int N,u,mx=LONG_MIN,mn=LONG_MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> u;
        mx=max(mx,u); mn=min(mn,u);
    }
    cout << mx << "\n" << mn;
}

