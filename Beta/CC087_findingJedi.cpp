#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M;
ll ans=0;
map <ll,ll> ct;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        ct[x]++;
    }

    for(int i=1;i<=M/2;i++){
        if(i==M/2){
            if (M%2 == 0) {ans += (ct[i] * (ct[i]-1))/2;}
            continue;
        }        
        ans += ct[i] * ct[M-i];
    }
    cout << ans;
}