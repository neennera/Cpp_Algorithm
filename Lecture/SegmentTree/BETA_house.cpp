#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define SZ_MAX (1<<18)

int N,Q;
struct ST{
    vector <int> seg;

    void build(int node,int l,int r){
        if(node==1){
            seg.resize(SZ_MAX);
        }
        if(l==r){
            cin >> seg[node];
            return;
        }
        int child=node*2, m=(l+r)>>1;
        build(child,l,m);
        build(child+1,m+1,r);
        seg[node]=max(seg[child]+seg[child+1],max(seg[child],seg[child+1]));
    }

    int query(int node,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return -1;
        if(l>=ql&&r<=qr){
            return seg[node];
        }
        int child=node*2, m=(l+r)>>1;
        int lc=query(child,l,m,ql,qr), lr=query(child+1,m+1,r,ql,qr);
        return max(lc,lr);   
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q;
    struct ST st; st.build(1,0,N-1);
    int l,r;
    while(Q--){
        cin >> l >> r;
        cout << max(0,st.query(1,0,N-1,l,r)) << "\n";
    }
}