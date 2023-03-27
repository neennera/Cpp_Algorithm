#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0
int N,M;
ll sol[100005];
int pa[100005];
int fp(int n){
    if(pa[n]==n) return n;
    return pa[n]=fp(pa[n]);
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    memset(sol,0,sizeof(sol));
    for(int i=1;i<=N;i++){
        pa[i]=i;
        cin >> sol[i];
    }
    ll a,b,fa,fb;
    while(M--){
        cin >> a >> b;
        fa=fp(a), fb=fp(b);
        if(fa==fb){
            cout << "-1\n"; continue;
        }
        //let fa win
        if(sol[fb]>sol[fa]){swap(fa,fb);}
        else if(sol[fa]==sol[fb] && (fb<fa)){ swap(fa,fb); }
        cout << fa << "\n";
        sol[fa]+=(sol[fb]/2);
        pa[fb]=fa;
    }
}