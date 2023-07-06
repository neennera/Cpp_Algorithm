#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0


ll N,K;
unsigned ll ans=1e17, l=0,r=0,mid;
unsigned ll a[2000006];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
        r=max(r,a[i]);
    }

    while(l<r){
        ll ct=0;
        mid=(l+r)>>1;
        vector <ll> s;

        //cout << l << " " << mid << " " << r << "\n";
        for(int i=0;i<N;i++){
            if(a[i]<=mid) continue;
            else s.push_back(a[i]);
        }

        bool c=1;
        for(int i=0;i<s.size();i+=2){
            //cout << s[i] << " " << s[i+1] << " ";
            if(s[i]!=s[i+1]){
                l=mid+1;
                c=0;
                //break;
            }
        }

        if(c){
            ans=min(ans,mid);
            r=mid;
        }
        //cout << endl;
    }

    cout << ans;
}
/*
6
8 5 8 5 2 2
*/

