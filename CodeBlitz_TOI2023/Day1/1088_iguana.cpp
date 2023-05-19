#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,M,r,l;
ll ct[3]={0,0,0};
map <int,int> m;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    m[1]=0;
    m[N+1]=0;

    for(int i=0;i<M;i++){
        cin >> l >> r;
        m[l]++;
        m[r+1]--;
    }

    int id=0, sd=0;
    for(auto it=m.begin();it!=m.end();it++){
        if(id){
            ct[sd%3]+=((*it).ft)-id;
        }
        sd=sd+((*it).sd);
        id=((*it).ft);
    }
    char c; cin >> c;
    ll ans=0;
    switch(c){
        case 'R' : ans=((ct[1]*2) +ct[2]); break;
        case 'G' : ans=(ct[0] + (ct[2]*2)); break;
        case 'B' : ans=((ct[0]*2) +ct[1]); break;
    }
    cout << ans;
    return 0;
}