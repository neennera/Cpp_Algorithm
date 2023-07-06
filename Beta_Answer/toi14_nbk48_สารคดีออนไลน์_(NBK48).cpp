#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,Q,u;
deque <pii> q; //cost , toon
vector <pii> v;
ll temp=0;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> u;
        temp+=u;
        v.push_back({temp,i});
    }
    v.push_back({0,0});

    sort(v.begin(),v.end());
    for(auto [c,t]:v){
        if(q.empty()){
            q.push_back({c,t});
            continue;
        }
        if(q.back().sd >= t) continue;
        q.push_back({c,t});
    }


    while(Q--){
        ll u;
        cin >> u;
        auto it=lower_bound(q.begin(),q.end(),make_pair(u+1,0));
        it--;
        cout << (*it).sd << "\n";
    }
}

