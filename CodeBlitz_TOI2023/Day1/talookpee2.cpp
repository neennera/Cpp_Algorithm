#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
ll n,p,Q;
ll f(ll n){
    ll ans=1, N=n;
    while(N>1){
        ans = ans*N;
        N--;
    }
    return ans;
}
ll power(ll a,ll b){
    ll ans=0;
    while(b--){
        ans = ans*a;
    }
    return ans;
}
ll sub(ll n,ll p){
    ll ans=0;
    for(ll k=1;k<=n;k++){
        ans += ((ll)(f(n)/f(n-k)/f(k))* (ll)power(p*k,p*k) * (ll)pow(n-k+1,n-k-1))%p;
    }
    return ans;
}
int main(){
    cin >> Q;
	while(Q--){
		cin >> n >> p;
        cout<<"0\n";
        // subtask (40/100) :cout << sub(n,p) << "\n";
        // sol (100/100) : cout<<"0\n";
	}
	
}
