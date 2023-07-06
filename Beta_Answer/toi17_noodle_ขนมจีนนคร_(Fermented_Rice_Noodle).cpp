#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,K;
ll fac[1000006];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> fac[i];

    ll l=0, r=1e18, mid;
    ll ans=0;


    while(l<=r){
        priority_queue <int, vector<int>, greater<int>> pq;
        mid=(l+r)>>1;
        int ct=0,tc=0;
        ll temp=0, mm=1e18;

        for(int i=1;i<=N;i++){
            temp+=fac[i];
            tc++;
            pq.push(fac[i]);

            if(tc>K){temp-=pq.top(); pq.pop(); tc--;}
            if(temp>=mid&&tc==K){
                ct++;
                mm=min(mm,temp);
                temp=0;
                tc=0;
                while(!pq.empty()) pq.pop();
            }
            if(ct>M) break;
        }
        //cout << l << " "<< mid << " "<< r << " " << ct << endl;
        //why r=mid?
        if(ct<M) r=mid;
        else{
            ans=max(ans,mm);
            l=mid;
        }
        if(l==r-1) break;
    }

    cout << ans;
}
/*
5 5 1
100 50 23 3 1
*/

