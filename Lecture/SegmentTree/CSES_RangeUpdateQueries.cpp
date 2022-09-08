#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int n,N,Q,id,l,r,ql,qr;
ll k;
vector <ll> seg;
ll a[200005];

void pf(){
    for(int i=1;i<=N;i*=2){
        for(int j=i;j<i*2;j++){
            cout << seg[j] << " ";
        }
        cout << '\n';
    }
}

ll f(int id){
    //pf();
    ll ans=a[id];
    for(id=N+id;id>=1;id/=2){
        //cout << ans << " - > ";
        ans+=seg[id];
    }
    return ans;
}

ll update(int now,int k,int l,int r,int ql,int qr){
    if(r<ql||l>qr) return 0;
    if(l>=ql&&r<=qr) return seg[now]+=k;

    int child=now*2, mid=(l+r)>>1;
    update(child,k,l,mid,ql,qr);
    update(child+1,k,mid+1,r,ql,qr);
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> Q;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    N=n;
    while(__builtin_popcount(N)!=1){N++;}
    seg.resize(2*N,0);

    int op;
    while(Q--){
        //pf();
        cin >> op;
        if(op==1){
            cin >> ql >> qr >> k;
            update(1,k,0,N-1,ql-1,qr-1);
        }else{
            cin >> k;
            cout << f(k-1) << "\n";
        }
    }
}