#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

struct DATA{
    int u,v,w,id;
    bool operator < (const DATA & d2) const{
        return w>d2.w;
    }
};

int N,M,u,v,w,id;
int pa[100000],cost[200000];
vector <pii> l;
priority_queue <DATA> pq;

int fp(int n){
    if(pa[n]==n) return n;
    return pa[n]=fp(pa[n]);
}

void join(int u,int v){
    int pu=fp(u), pv=fp(v);
    if(pu==pv)
        return;
    pa[pu]=pv;
    N--;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    for(int i=1;i<=N;i++){ pa[i]=i;}
    for(int i=0;i<M;i++){
        cin >> u >> v >> w;
        pq.push({u,v,w,i});
        cost[i]=w;
        if(i>N){ l.push_back({w,id});}
    }

    sort(l.begin(),l.end());

    while(N>1){
        auto temp = pq.top(); pq.pop();
        u=temp.u, v=temp.v, w=temp.w, id=temp.id;

        
        if(id<=N){
            join(u,v);
        }else{
            //std::cout << "--" << w << "\n";
            priority_queue <DATA> copy;
            while(pq.top().id > N){
                copy.push(pq.top()); pq.pop();
            }
            int k = pq.top().w;
            while(!copy.empty()){
                pq.push(copy.top()); copy.pop();
            }
            //std::cout << k;
            k++;
            auto it=lower_bound(l.begin(),l.end(),make_pair(k+1,-1));
            if(it == l.end()){ std::cout << 0; return 0;}
            swap(cost[((*it).second)],cost[id]);
            l.erase(it);
        }
    }


    std::cout << 1;
    for(int i=N;i<M;i++){
        std::cout << cost[i] << "\n";
    }
    
    return 0;
}