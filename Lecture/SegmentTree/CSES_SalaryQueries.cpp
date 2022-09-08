#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>using Tree = tree<
    T,null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update
>;

ll N,k,Q,id;
char c;
ll m[200005];
Tree <pii> t;
const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N>> Q;
    for(int i=1;i<=N;i++){
        cin >> m[i];
        t.insert({m[i],i});
    }

    while(Q--){
        cin >> c;
        if(c=='!'){
            cin >> id >> k;
            //id--;
            t.erase({m[id],id});
            m[id]=k;
            t.insert({m[id],id});
        }else{
            int ql,qr;
            cin >> ql >> qr;
            //ql--, qr--;
            cout << t.order_of_key({qr,MOD}) - 
                    t.order_of_key({ql-1,MOD}) << "\n";
        }
    }

}