#include<bits/stdc++.h>
using namespace std;
 
int N,M,K,x,ans=0;
vector <int> a;
 
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> x; a.push_back(x);
    }
    sort(a.begin(),a.end());
 
    int i=0,j=N-1;
    while(i<j){
        if(a[j]+a[i]>K){j--; ans++;}
        else{i++, j--, ans++;}
    }
    if(i==j) ans++;
 
    cout << ans;
 
    return 0;
}