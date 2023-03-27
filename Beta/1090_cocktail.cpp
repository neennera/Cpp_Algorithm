#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N,M,k;
ll ans=0;
ll num[1000007];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(num,0,sizeof(num));
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> k;
        num[k]++;
    }
    cin >> M;

    for(int i=0;i<=(M/2);i++){
        if(i==M-i){
            ans += (num[i]*(num[i]-1))/2;
        }else{
            ans += num[i]*num[M-i];
        }
    }

    cout << ans;
}