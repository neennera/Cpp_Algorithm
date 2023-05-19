#include<bits/stdc++.h>
using namespace std;
 
int N,s,f;
map <int,int> m;
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> N;
    for( int i=0 ; i<N ; i++){
        cin >> s >> f;
        m[s]+=1, m[f+1]-=1;
    }
 
    int ans=0, temp=0;
    for(auto [s,f]:m){
        temp+=f;
        ans=max(ans,temp);
    }
    cout << ans;
 
    return 0;
}