#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll ans=0,n;
    cin >> n;
    ans+=(n/15)*3000;
    n%=15;
    if(n>=8) ans+=3000;
    else if(n==7) ans+=2300;
    else if(n==6) ans+=2000;
    else if(n==5||n==4) ans+=1500;
    else if(n==3) ans+=1300;
    else if(n==2) ans+=800;
    else if(n==1) ans+=500;

    cout << ans;
}



