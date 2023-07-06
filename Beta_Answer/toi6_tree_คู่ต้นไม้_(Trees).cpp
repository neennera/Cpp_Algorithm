#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int Q=5,N,u,v;
    while(Q--){
        cin >> N;
        vector <pii> a;
        vector <pii> b;
        for(int i=0;i<N-1;i++){
            cin >> u >> v;
            if(v<u) swap(u,v);
            a.push_back({u,v});
        }
        sort(a.begin(),a.end());
        for(int i=0;i<N-1;i++){
            cin >> u >> v;
            if(v<u) swap(u,v);
            b.push_back({u,v});
        }
        sort(b.begin(),b.end());

        if(a==b)cout << "Y";
        else cout << "N";
    }
}
/*
2 2
1 1
1 2
1 1
1 1
*/

