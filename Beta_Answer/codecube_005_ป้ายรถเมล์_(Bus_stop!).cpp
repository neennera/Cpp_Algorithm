#include<bits/stdc++.h>
using namespace std;

long long N,G;
vector <long long> brick;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    brick.resize(N);
    for(int i=0;i<N;i++){
        cin >> brick[i];
        if(!i) G=brick[i];
        G=G*brick[i]/(__gcd(G,brick[i]));
    }
    cout << G;
}

