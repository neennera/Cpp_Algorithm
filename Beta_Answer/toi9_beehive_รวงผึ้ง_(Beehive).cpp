#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,K;
int a[5000006];
set <int> s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(a,0,sizeof(a));
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> a[i];
    for(int i=1;i<=N;i++){
        if(a[i]>a[i-1]&& a[i]>a[i+1]){
            s.insert(a[i]);
        }
    }

    if(s.empty()){
        cout << "-1"; return 0;
    }
    auto it=s.end();
    it--;
    for(;it!=s.begin();it--){
        if(!K) break;
        cout << *it << "\n";
        K--;
    }
}

