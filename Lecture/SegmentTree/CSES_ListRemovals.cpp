#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define pii pair<int,int>

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>using Tree = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update
>;

int N,a,b;
Tree <pii> t;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;    
    for(int i=0;i<N;i++){
        cin >> a;
        t.insert(make_pair(i,a));
    }

    for(int i=0;i<N;i++){
        cin >> a;
        auto temp = (t.find_by_order(--a));
        cout << (*(temp)).sd << " ";
        t.erase(temp);
    }
}