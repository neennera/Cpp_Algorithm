#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,M,K;
int u;
set <int> s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;
    while(M--){
        int r,l;
        cin >> r >> l;
        if(s.find(r)==s.end()){s.insert(r);}else{s.erase(r);}
        if(s.find(r+l)==s.end()){s.insert(r+l);}else{s.erase(r+l);}
    }
    s.insert(1);
    s.insert(N+1);

    //for(auto x:s) cout << x <<" ";
    //cout << endl;

    while(K--){
        cin >> u;
        auto r=s.upper_bound(u);
        auto l=s.upper_bound(u); l--;
        cout << *r-*l << "\n";
    }
}
/*
5 2 5
2 4
3 5
1
2
3
4
5
*/

