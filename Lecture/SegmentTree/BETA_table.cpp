#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int R,C,Q,N;
struct ST{
    vector <int> seg;
    vector <int> lazy;

    void build(int n){
        N=1;
        while(N<n){N<<=1;}
        seg.resize(2*N,0), lazy.resize(2*N,0);
    }

    void prop(int node){
        if(lazy[node]==0) return;
        int child = node*2, k=lazy[node];
        seg[node]=k;
        lazy[node]=0;
        if(node<N)
            lazy[child]=k, lazy[child+1]=k;
    }

    int f(int node,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return -1;
        prop(node);
        if(l>=ql && r<=qr){
            return seg[node];
        }   
        int child=node*2, m=(l+r)>>1;
        return max(f(child,l,m,ql,qr), f(child+1,m+1,r,ql,qr));
    }

    void update(int node,int k,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return;
        prop(node);
        if(l>=ql && r<=qr){
            lazy[node]=k;
            return; 
        }

        int child=node*2, m=(l+r)>>1;
        update(child,k,l,m,ql,qr); prop(child);
        update(child+1,k,m+1,r,ql,qr); prop(child+1);
        
        seg[node]=min(seg[child],seg[child+1]);
    }

    void pf(){
        cout << "pf-----\n";
        for(int i=1;i<=N;i*=2){
            for(int j=i;j<i*2;j++){
                cout << seg[i] << " ";
            }
            cout << endl;
        }

        for(int i=1;i<=N;i*=2){
            for(int j=i;j<i*2;j++){
                cout << lazy[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    //ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C >> Q;
    int op,r,c,k;
    struct ST st; st.build(R*C);
    //st.pf();
    while(Q--){
        cin >> op;
        if(op==1){
            cin >> r >> c >> k;
            r--;
            st.update(1,k,0,N-1,(r*R) + c,(r*R) + c);
        }else if(op==2){
            cin >> r >> k;
            r--;
            st.update(1,k,0,N-1,(r*R),((r+1)*R)-1);
        }else if(op==3){
            cin >> r;
            r--;
            cout << st.f(1,0,N-1,r*R, (r+1)*R -1) << "\n";
        }else{
            cout << st.seg[1] << "\n";
        }
        st.pf();
    }
}