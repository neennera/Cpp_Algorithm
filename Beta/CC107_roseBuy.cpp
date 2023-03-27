#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define ll long long

int N, K, id;
ll qs[1000005],x;
ll ans=LLONG_MIN;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    qs[0]=0;
    for(int i=1;i<=N;i++){
        cin >> x;
        qs[i]=qs[i-1]+x;
    }

    // find Longest subsequence having maximum sum
    // let "id" be first index to pick up ; we want low qs[id]
    for(int i=K;i<=N;i++){
        if(qs[i-K]<qs[id]) id=i-K; // find better index to pick up
        ans = max(ans, qs[i] - qs[id]);
    }

    cout << ans;
}