#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,u;
int a[1000006], dp[1000006];
deque <pair<int,int>> r,l;  // high building from R,L

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0,sizeof(dp));
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }

    for(int i=1;i<=N;i++){      
            // lower building can reach if a higher building block the way
        while(!r.empty()&&r.back().ft<=a[i]) r.pop_back(); 

        if(r.empty()){
            dp[i] += i-1;
        }else{
            dp[i] += i-r.back().sd-1;
        }
        
        r.push_back({a[i],i});
    }

    for(int i=N;i>=1;i--){
        while(!l.empty()&&l.back().ft<=a[i]) l.pop_back();

        if(l.empty()){
            dp[i] += N-i;
        }else{
            dp[i] += l.back().sd-i-1;
        }

        l.push_back({a[i],i});
    }

    for(int i=1;i<=N;i++){
        cout << dp[i]+1 << " ";
    }
}
