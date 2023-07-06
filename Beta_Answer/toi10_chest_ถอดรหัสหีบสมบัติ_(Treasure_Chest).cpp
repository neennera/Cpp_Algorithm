#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0
struct DATA{ ll a,b,c,d; //num of 2,3,5,7
};
ll N,M,x;
ll a,b;
map <ll,DATA> m;
void add(ll id,int k,int h){
    if(h==-1) id++;
    switch(k){
        case 2 : m[id].a += (h); break;
        case 3 : m[id].b += (h); break;
        case 4 : m[id].a += (2*h); break;
        case 5 : m[id].c += (h); break;
        case 6 : m[id].a += (h); m[id].b += (h); break;
        case 7 : m[id].d += (h); break;
        case 8 : m[id].a += (3*h); break;
        case 9 : m[id].b += (2*h); break;
        case 10 : m[id].a += (h); m[id].c += (h); break;
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    m[0]={0,0,0,0};
    m[M]={0,0,0,0};
    for(ll i=0;i<N;i++){
        cin >> x >> a >> b;
        add(a,x,1);
        add(b,x,-1);
    }
    ll ans=1,temp=0, ct=0;
    //int last=0;
    struct DATA sdd={0,0,0,0};
    for(auto it=m.begin();it!=m.end();it++){
        sdd.a+=(*it).sd.a;
        sdd.b+=(*it).sd.b;
        sdd.c+=(*it).sd.c;
        sdd.d+=(*it).sd.d;
        temp=(sdd.a+1)*(sdd.b+1)*(sdd.c+1)*(sdd.d+1);
        if(temp==ans){
            auto itt=it; itt++;
            if(itt!=m.end())
                ct+=((*itt).ft-(*it).ft);
        }
        if(temp>ans){
            ans=temp;
            auto itt=it; itt++;
            if(itt!=m.end())
                ct=((*itt).ft-(*it).ft);
        }
        //last=(*it).ft;
    }
    cout << ans <<" " << ct;
}

