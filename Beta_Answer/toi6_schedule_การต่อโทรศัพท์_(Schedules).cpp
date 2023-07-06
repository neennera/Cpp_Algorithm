#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

struct DATA{
    int a,c,i;
    bool operator < (const DATA& d2) const{
        if(a==d2.a) return c>d2.c;
        return a>d2.a;
    }
};

int N,K,M;
priority_queue <DATA> q;
bitset <500005> gt;
int a,b,c,i,ct=0;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K >> M;
    for(int i=1;i<=N;i++){
        cin >> a >> b;
        q.push({a,1,i});
        q.push({b+1,-1,i});
    }

    while(!q.empty()){
        a=q.top().a;
        c=q.top().c;
        i=q.top().i;
        q.pop();

        if(c==1){
            if(ct<K){
                ct++;
                gt[i]=1;
            }else{
                gt[i]=0;
            }
        }else{
            if(gt[i]){
                ct--;
            }
        }
    }

    while(M--){
        cin >> i;
        if(gt[i]) cout << "Y ";
        else cout << "N ";
    }
}

