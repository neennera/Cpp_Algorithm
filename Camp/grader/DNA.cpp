#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,Q,op,a,b;

struct DATA{ int d,g;};

struct Tree{
    struct DATA tree[1200000];
    int build(int node,int l,int r){
        if(l==r){
            tree[node].d=0;
        }

        int child=node*2, k=(l+r)>>1;
        build(child,l,k);
        build(child+1,k+1,r);
    }

    int remember(int node,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return 0;
        if(l>=ql&&r<=qr) return abs(tree[node].d)+abs(tree[node].g);

        int child=node*2, k=(l+r)>>1;
        return remember(child,l,k,ql,qr)+remember(child+1,k+1,r,ql,qr);
    }

    int del(int node,int l,int r,int ql,int qr){
        int child=node*2, k=(l+r)>>1, id = - tree[child].d + tree[child].g;
        int now = - tree[node].d + tree[node].g;

        if(l >= ql && r + now <= qr){

        }

        if(k + id>= ql){
            del(child,l,k + id,ql,qr);
        }else{
            del(child+1,k + id +1,r,ql,qr);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    return 0;
}