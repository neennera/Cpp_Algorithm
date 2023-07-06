#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,K;
ll a[1005];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> a[i];

    ll l=0,r=1e18,mid,ans=LLONG_MAX;
    while(l<r){
        mid=(l+r)>>1;
        bool c=0;
        ll temp=0, ct=1,M=INT_MIN;
        for(int i=0;i<N;i++){
            if(a[i]>mid){ct=K+1; break;}
            if(a[i]+temp>mid){
                M=max(M,temp);
                ct++;
                temp=a[i];
                if(ct>K) break;
                continue;
            }
            temp+=a[i];
        }
        M=max(M,temp);

        if(ct==K){ ans=min(ans,M);}
        if(ct>K){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout << l;
}
/*
5 3
1 5 1 1 1
*/

