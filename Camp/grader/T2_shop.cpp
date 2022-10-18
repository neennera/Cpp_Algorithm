#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,Q,L= 0,op, id,p;
vector <list<int>> costumer(120005);
ll revenue[1200005],shop[120005];
map <int,int> m;

void cost(int id,int p){
    for(auto v : costumer[id]){
        revenue[v]= revenue[v]-shop[id]+p;
    }
    shop[id]=p;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(revenue,0,sizeof(revenue));
    memset(shop,0,sizeof(shop));
    cin >> N >> M >> Q;

    for(int i=1;i<=M;i++){
        cin >> p;
        for(int j=0;j<p;j++){
            cin >> id;
            costumer[i].push_back(id);
        }
        L=max(L,p);
    }
    while(Q--){
        cin >> op >> id;
        if(op==1){
            cin >> p;
            if(L<=5) cost(id,p);
            else m[id]=p;
        }else{
            for(auto [shop,p]:m){
                if(m[shop]==0) continue;
                cost(shop,p);
                m[shop]=0;
            }
            cout << revenue[id] << "\n";
        }
    }
    return 0;
}