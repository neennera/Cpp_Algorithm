#include<bits/stdc++.h>
using namespace std;

int N,G;
long long ans;
vector <int> brick;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    brick.resize(N);
    for(int i=0;i<N;i++){
        cin >> brick[i];
        if(!i) G=brick[i];
        G=__gcd(G,brick[i]);
    }
    for(int i=0;i<N;i++){
        ans+=(brick[i]/G);
    }
    cout << ans;
}

