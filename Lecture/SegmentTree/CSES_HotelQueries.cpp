#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define ed "\n"

int n,N,Q,k;


struct SegTree{
    vector <int> seg;

    void build(){
        N=1; while(N<n){N <<=1; }
        seg.resize(2*N,0);
        assign(1,0,N-1);
    }

    int assign(int node,int l,int r){
        if(l==r){
            if(l<n) cin >> seg[node];
            else seg[node]=0;
            return seg[node];
        }
        int child= node*2, m=(l+r)>>1;
        assign(child,l,m);
        assign(child+1,m+1,r);

        return seg[node]=max(seg[child],seg[child+1]);
    }


    int f(int k,int node=1,int l=0,int r=N-1){
        int m=(l+r)>>1, child=node*2, ans;
        if(l==r){
            seg[node]-=k;
            return l;
        }

       (seg[child]>=k) ? ans = f(k,child,l,m): ans = f(k,child+1,m+1,r);
        
        seg[node]=max(seg[child],seg[child+1]);
        return ans;
    }
};




int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    SegTree st;
    cin >> n >> Q;
    
    st.build();

    while(Q--){
        cin >> k;
        if(st.seg[1]<k){cout << "0 ";}
        else{
            cout << st.f(k)+1 << " ";
        }
        
    }
}