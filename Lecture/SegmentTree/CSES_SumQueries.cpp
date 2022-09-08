#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ft first
#define sd second

ll n,N=1,Q,k,id;
ll ql,qr,l,r;
vector <ll> seg;

void pf(){
    for(ll i=1;i<N;i*=2){
        for(ll j=i;j<i*2;j++){
            cout << seg[j] <<" ";
        }
        cout << endl;
    }
}

ll f(ll pos,ll l, ll r, ll ql,ll qr){

    //cout << "--> " << l << " " << r << "\n";

    if(l>qr||r<ql||l>r) return 0;
    if(l>=ql&&r<=qr) return seg[pos];

    ll k=(l+r)>>1, child=pos<<1;
    return f(child,l,k,ql,qr) + f(child+1,k+1,r,ql,qr);
}

ll update(ll id, ll k){
    seg[id]=k;
    for(ll i=id>>1;i>=1;i/=2){
        seg[i]=seg[2*i]+seg[(2*i)+1];
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> Q;
    while(N<2*n){ N*=2;}
    seg.resize(2*N,0);
    
    for(ll i=0;i<n;i++){
        cin >> seg[(N>>1)+i];
    }
    for(ll i=(N/2)-1;i>=1;i/=2){
        for(ll j=i;j>(i/2);j--){
            seg[j]=seg[j*2]+seg[(j*2)+1];
        }
    }

    //pf();
    int op;
    while(Q--){
        cin >> op;
        //cout << op << "--- ";
        if(op==2){
            cin >> ql >> qr;
            cout << f(1,0,(N/2)-1,ql-1,qr-1) << "\n";
        }else{
            cin >> id >> k;
            update((N/2)+(id-1),k);
            //cout << "updated\n";
            //pf();
        }
        
    }
}

