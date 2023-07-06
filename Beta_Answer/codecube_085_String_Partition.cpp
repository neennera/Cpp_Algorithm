#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>
#define db 0

string s;
int N;
ll ans=1e7;
int ct[27];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    cin >> s;
    N=s.length();
    for(int k=1;k<=N/2;k++){
        if(N%k) continue;
        ll temp=0;
        for(int i=0;i<k;i++){
            memset(ct,0,sizeof(ct));
            for(int j=i;j<N;j+=k){
                ct[s[j]-'a']++;
            }
            int m=1;
            for(int j=0;j<26;j++){
                m=max(m,ct[j]);
            }
            temp+=(N/k)-m;
        }
        ans=min(ans,temp);
    }

    cout << ans;
}

