#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0
ll N,K;
ll ans=1e17, l=1,r=1e17,mid;
ll a[1000006];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    while(l<r){
        ll ct=0;
        mid=(l+r)>>1;
        for(int i=0;i<N;i++){
            ct+=(mid/a[i]);
            if(ct>K) break;
        }
        if(ct<K){
            l=mid+1;
        }else{
            ans=min(ans,mid);
            r=mid;
        }
        //cout << mid << " " << ct << "\n";
    }
    cout << ans;
}