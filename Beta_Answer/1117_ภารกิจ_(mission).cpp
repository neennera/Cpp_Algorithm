#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

struct DATA{
    int A, B;
    bool operator < (const DATA & d2) const{
        return (B - 2*A ) < (d2.B - 2* d2.A); 
    }
};

ll ans=INT_MIN,temp=0; // ans be INT_MIN cause max can <0
int N,A,B;
priority_queue <DATA> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        q.push({A,B});
    }

    for(int i=1;i<=N;i++){
        temp+= ( q.top().B - 2*q.top().A); q.pop();
        ans = max(ans, (ll)(temp - pow(N-i,2)) ); 
    }
    cout << ans;
}

