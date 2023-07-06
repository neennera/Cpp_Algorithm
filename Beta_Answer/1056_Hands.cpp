#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,K,u;
priority_queue <int> q;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> u;
        q.push(u);
    }

    ll ans=0;
    while(!q.empty()){
        ans+=q.top(); q.pop();
        int ct=K-1;
        while(ct&&!q.empty()){
            //cout << q.top() << " ";
            q.pop(); ct--;
        }
        //cout << "\n";
    }
    cout << ans;
}

