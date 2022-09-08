#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
	T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update
>;

int N,Q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> Q;

    while(Q--){
        cin >> N;
        ll ans=0;

        Tree <int> t;

        int a;
        for(int i=0;i<N;i++){
            cin >> a;
            ans += t.order_of_key(-a);
            t.insert(-a);
        }

        cout << ans << "\n";
    }
}