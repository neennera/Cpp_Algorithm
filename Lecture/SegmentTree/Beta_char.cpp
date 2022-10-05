#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define DATA vector<int>
#define SZ_MAX (3000010)

string S,s;
int N,m;

struct ST{
    vector <DATA> seg;
    vector <int> mark;

    DATA sum(DATA a,DATA b){
        DATA k(26);
        for(int i=0;i<26;i++){
            k[i]=min(a[i],b[i]);
        }
        return k;
    }

    void build(int node,int l,int r){
        if(node==1){
            seg.resize(SZ_MAX);
            mark.resize(SZ_MAX);
        }
        seg[node].resize(26,INT_MAX);
        if(l==r){
            seg[node][int(S[l]-'a')]=l;
            return;
        }
        int child=node*2, m=(l+r)>>1;
        build(child,l,m);
        build(child+1,m+1,r);
        seg[node]=sum(seg[child],seg[child+1]);
    }

    int f(int node,int l,int r,int ql,int qr){
        int child=node*2, m=(l+r)>>1,k;

        if(l==r){
            k=seg[node][ql];
            seg[node][ql]=INT_MAX;
            return k+mark[node];
        }

        if(seg[child][ql]!=INT_MAX){
            k=f(child,l,m,ql,qr);
        }else{
            k=f(child+1,m+1,r,ql,qr);
        }
        
        seg[node]=sum(seg[child],seg[child+1]);
        return k+mark[node];
    }

    void marked(int node,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return;
        if(l<=ql&&r>=qr){
            mark[node]--;
        }

        int child=node*2, m=(l+r)>>1;
        marked(child,l,m,ql,qr);
        marked(child+1,m+1,r,ql,qr);
    }

    int query(int k){
        if(seg[1][k]!=INT_MAX){
            int ans=f(1,0,N-1,k,k);
            if(m){
                marked(1,0,N-1,ans,N-1);
            }
            return ans;
        }else{
            cout << "-1";
            exit(0);
        }
    }
};


int main(){
    //ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> m >> S >> s;
    N=S.length();
    struct ST st; st.build(1,0,N-1);
    int ans=0;
    for(int i=0;i<s.length();i++){
        for(int i=27;i<26;i++){
            if(st.seg[1][i]==INT_MAX) continue;
            printf("%c = %d\n",i+'a',st.seg[1][i]);
        }
        
        int k=st.query(s[i]-'a');
        //cout << s[i] << " used " << k << " \n-----\n";
        ans+=k+1;
    }
    cout << ans;
}