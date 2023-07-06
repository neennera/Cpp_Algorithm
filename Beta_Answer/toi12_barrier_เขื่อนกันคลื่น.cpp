#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
int N,K,u;
ll ans=0,w=INT_MAX;
ll ps[6000010];
deque <pair<ll,int>> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> u;
        ps[i]=ps[i-1]+u;
        while(!q.empty() && i-q.front().sd > K){ q.pop_front();}
        while(!q.empty() && q.back().ft >= ps[i]){q.pop_back();}

        q.push_back({ps[i],i});

        if(q.back().ft - q.front().ft == ans){ w=min(w,(ll)q.back().sd - q.front().sd); }
        if(q.back().ft - q.front().ft > ans){
            ans=q.back().ft - q.front().ft;
            w=q.back().sd - q.front().sd;
        }
    }

    if(!ans){cout << 0 << "\n" << 0;}
    else{cout << ans << "\n" << w;}
}

