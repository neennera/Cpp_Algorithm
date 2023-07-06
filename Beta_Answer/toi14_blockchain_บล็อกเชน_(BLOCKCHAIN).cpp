#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

map <vector<pii>,int> m;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int Q,N,u,v;
    cin >> N >> Q;
    while(N--){
        int n;
        cin >> n;
        vector <pii> a;
        for(int i=0;i<n-1;i++){
            cin >> u >> v;
            if(v<u) swap(u,v);
            a.push_back({u,v});
        }
        sort(a.begin(),a.end());
        m[a]++;
    }
    while(Q--){
        int n;
        cin >> n;
        vector <pii> a;
        for(int i=0;i<n-1;i++){
            cin >> u >> v;
            if(v<u) swap(u,v);
            a.push_back({u,v});
        }
        sort(a.begin(),a.end());
        cout << m[a] << "\n";
    }
}
/*
2 2
1 1
1 2
1 1
1 1
*/

