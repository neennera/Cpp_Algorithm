#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,a[105],M;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> M >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }

    ll l=1, r=150000, mid, ans=150000;
    while(l<r){
        mid=(l+r)>>1;
        ll ct=0, temp=0;
        //cout << l << " " << mid << " " << r << endl;
        bool c=true;
        for(int i=0;i<N;i++){
            if(a[i]>mid){c=false; break;}
            if(a[i]>temp){
                ct++; temp=mid-a[i];
            }else{
                temp-=a[i];
            }
            if(ct>M) break;
        }

        //cout << mid << "  " << ct << endl;

        if(ct<=M&&c){
            ans=min(ans,mid);
            r=mid;
        }else{
            l=mid+1;
        }
        //t << l << " " << mid << " " << r << endl;
    }

    cout << ans;
}
/*
1 1
800
*/

