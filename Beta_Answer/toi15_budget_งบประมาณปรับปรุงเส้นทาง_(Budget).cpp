#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 0

struct DATA{
    int u,v,w;
    bool operator < (const DATA &d2) const{
        return w>d2.w;
    }
};

int N,M,K;
int pa[3003];
int u,v,w,c;
priority_queue <DATA> q;

int fp(int n){
    if(pa[n]==n) return n;
    return pa[n]=fp(pa[n]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int ru,rv;
    cin >> N >> M;
    for(int i=0;i<N;i++){ pa[i]=i;}
    for(int i=0;i<M;i++){
        cin >> u >> v >> w >> c;
        if(c==1){
            ru=fp(u), rv=fp(v);
            if(ru==rv) continue;
            pa[ru]=rv;
            N--;
        }else{
            q.push({u,v,w});
        }
    }

    vector <pii> ve; //dis cost
    cin >> K;
    int d,c;
    for(int i=0;i<K;i++){
        cin >> d >> c;
        ve.push_back({d,c});
    }
    sort(ve.begin(),ve.end());

    deque <pii> al;
    al.push_back({0,0});
    for(int i=0;i<ve.size();i++){
        d=ve[i].ft, c=ve[i].sd;
        while(!al.empty()&& al.back().sd >= c) al.pop_back();
        al.push_back({d,c});
    }

    /*
    for(auto [d,c]:al){
        cout << d << "," <<c << " ";
    }
    cout << endl;
    */

    ll ans=0;
    while(!q.empty()&&N>1){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        q.pop();
        ru=fp(u), rv=fp(v);

        //cout << ru << " " << rv << "\n";
        if(ru==rv) continue;
        pa[ru]=rv;
        auto it=lower_bound(al.begin(),al.end(),make_pair(w,0));
        ans+=(*it).sd;
        N--;
    }
    cout << ans;
}

