#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,id,u;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> u;
        id=upper_bound(a.begin(),a.end(),u)-a.begin();
        if(id==a.size()){
            a.push_back(u);
        }else{
            a[id]=u;
        }
    }

    cout << N-a.size();
}

