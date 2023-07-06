#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define MAX_SIZE 30000
int R,C,Q,N;
struct ST{
    vector <int> seg;
    vector <int> lazy;

    void build(int node,int l,int r){
        if(node==1){
            seg.resize(MAX_SIZE);
            lazy.resize(MAX_SIZE);
        }
        if(l==r){
            seg[node]=0;
            return;
        }

        int child=node*2, m=(l+r)>>1;
        build(child,l,m);
        build(child+1,m+1,r);
        seg[node]=min(seg[child],seg[child+1]);
    }

    void prop(int node,int l,int r){
        if(lazy[node]==0) return;
        seg[node]=lazy[node];
        int child=node*2;

        if(l!=r){
            lazy[child] = lazy[node];
            lazy[child+1] = lazy[node];
        }
        
        lazy[node]=0;
    }

    void update(int node,int k,int l,int r,int ql,int qr){
        prop(node,l,r);
        if(l>qr || r<ql) return;        
        if(l>=ql&&r<=qr){
            lazy[node]=k;
            prop(node,l,r);
            return;
        }

        int child=node*2, m=(l+r)>>1;
        update(child,k,l,m,ql,qr);
        update(child+1,k,m+1,r,ql,qr);

        seg[node]=min(seg[child],seg[child+1]);
    }

    int get_value(int node,int l,int r,int ql,int qr){
        prop(node,l,r);
        if(l>qr||r<ql) return INT_MAX;
        if(l==r){
            prop(node,l,r);
            return seg[node];
        }
        
        int child=node*2, m=(l+r)>>1;
        return min(get_value(child,l,m,ql,qr),get_value(child+1,m+1,r,ql,qr));
    }

    void pf(){
        cout << "\npf(); \n";
        for(int i=1;i<2*C;i++){
            for(int j=i;j<2*i;j++){
                cout << seg[i] << " ";
            }
            cout << endl;
        }

        for(int i=1;i<2*C;i++){
            for(int j=i;j<2*i;j++){
                cout << lazy[i] << " ";
            }
            cout << endl;
        }
    }

    void pff(int node,int l,int r){
        if(l==r){
            return;
        }
        int child=node*2, m=(l+r)>>1;
        pff(child,l,m); pff(child+1,m+1,r);

        cout << seg[child] << " " << seg[child+1] <<" ";

        if(r==C-1){
            cout << "\n";
        }

        if(node==1){
            cout << seg[node] <<"\n";
        }
        
        
        //cout << " " << l << "," << r << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C >> Q;
    int op,r,c,k;
    struct ST st[R];
    for(int i=0;i<R;i++){
        st[i].build(1,0,C-1);
    }       

    while(Q--){
        cin >> op;
        if(op==1){
            cin >> r >> c >> k;
            r--; c--;
            st[r].update(1,k,0,C-1,c,c);
        }else if(op==2){
            cin >> r >> k;
            r--;
            st[r].update(1,k,0,C-1,0,C-1);
        }else if(op==3){
            cin >> r >> c;
            r--; c--;
            cout << st[r].get_value(1,0,C-1,c,c) << "\n";
        }else{
            int temp=INT_MAX;
            for(int i=0;i<R;i++){
                st[i].prop(1,0,N-1);
                temp=min(temp,st[i].seg[1]);
            }
            cout << temp << "\n";
        }
        //st[r].pff(1,0,C-1);
    }
}
