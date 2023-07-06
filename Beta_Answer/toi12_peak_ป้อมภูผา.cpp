#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,K;
int a[(int)5e6 +2];
bitset <(int)1e9+ 2> add;
vector <int> v;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N >> K;
    memset(a,0,sizeof(a));
   for(int i=1;i<=N;i++) cin >> a[i];
   for(int i=1;i<=N;i++){
     if(a[i]<=a[i-1]||a[i]<= a[i+1]) continue;
     if(add[a[i]]) continue;
     add[a[i]]=1;
     v.push_back(a[i]);
   }

   if(v.empty()){cout << "-1"; return 0;}

   if(v.size()<K){
    sort(v.begin(),v.end());
    for(auto x:v) cout << x << "\n";
   }else{
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<K;i++) cout << v[i] << "\n";
    //for(int i=0;i<v.size();i++) cout << v[i] << "\n";
   }
}

