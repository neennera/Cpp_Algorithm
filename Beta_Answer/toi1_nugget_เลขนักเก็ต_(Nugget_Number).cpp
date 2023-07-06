#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N;
bool dp[105];
queue <int> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    memset(dp,0,105);
    dp[0]=1;
    cin >> N;
    if(N<6){cout << "no"; return 0;}

    for(int i=6;i<=N;i++){
        if(i>=6) dp[i]|=dp[i-6];
        if(i>=9) dp[i]|=dp[i-9];
        if(i>=20) dp[i]|=dp[i-20];
        if(dp[i]){
            q.push(i);
        }
    }

    if(q.empty()){
        cout << "no";
    }else{
        while(!q.empty()){
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}

