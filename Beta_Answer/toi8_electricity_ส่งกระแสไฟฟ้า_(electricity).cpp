#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>
#define db 0

ll N,K,u;
deque <pii> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K >> u;
    q.push_back({1,u});
    for(int i=2;i<=N;i++){
        cin >> u;

        while(!q.empty()&&i-q.front().ft>K) q.pop_front();

        ll temp=q.front().sd+u;
        while(!q.empty()&&q.back().sd>temp&&q.back().ft!=1) q.pop_back();
        q.push_back({i,temp});
    }

    cout << q.back().sd;
    return 0;
}
/*
10 2
5 7
2 4
B
*/


