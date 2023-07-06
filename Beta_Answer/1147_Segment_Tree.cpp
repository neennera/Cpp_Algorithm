#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,ll>
#define db 0

void USA(){
    freopen("superbull.in","r", stdin);
    freopen("superbull.out","w", stdout);
}

int N,Q,M,ql,qr;
vector <ll> a;
char op;
ll k;

ll f(int node,int l,int r){
    if(r<ql||l>qr){
        return LLONG_MIN;
    }

    if(l>=ql&&r<=qr){
        return a[node];
    }


    int child=node*2, k=(l+r)>>1;
    return max(f(child,l,k),f(child+1,k+1,r));
}

void update(int id,ll k){
    a[id]=k;
    id/=2;
    while(id>0){
        a[id]=max(a[id*2],a[(id*2)+1]);
        id/=2;
    }
}

void pf(){
    for(int i=1;i<=M;i*=2){
        for(int j=i;j<i*2;j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q;
    M=N;
    while(__builtin_popcount(M)!=1){ M++; }
    a.resize(M*2,0);

    while(Q--){
        cin >> op;
        if(op=='U'){
            cin >> ql >> k;
            ql--;
            update(M+ql,k);
            //pf();
        }
        else{
            cin >> ql >> qr;
            ql--, qr--;
            cout << f(1,0,M-1) << "\n";
        }
    }
}
/*
6 4
U 3 280
U 1 7
U 2 9
P 1 3
*/

