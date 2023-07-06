#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,ll>

int N;
char a[260];
bool dp[260][260][3];
bool vis[260][260][3];

vector <pii> m[3];

int solve(int n,int l,int r){
    if(vis[l][r][n]) return dp[l][r][n];
    vis[l][r][n]=1;

    if(l==r) return dp[l][r][n]=(a[l]==n);

    for(int k=l;k<r;k++){
        for(auto [s,e]:m[n]){

            bool al=solve(s,l,k);
            bool ar=solve(e,k+1,r);
            dp[l][r][n]|=al&&ar;
            if(dp[l][r][n]){
                k=r;
                break;
            }
        }
    }
    return dp[l][r][n];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    m[2].push_back({0,0});
    m[2].push_back({1,0});
    m[2].push_back({2,1});
    m[1].push_back({0,1});
    m[1].push_back({1,1});
    m[1].push_back({1,2});
    m[1].push_back({2,0});
    m[1].push_back({2,2});
    m[0].push_back({0,2});

    int k=20;
    while(k--){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));

        cin >> N;
        string s;
        cin >> s;
        for(int i=0;i<N;i++) a[i]=s[i]-'0';
        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << dp[i][j][0] << ","<< dp[i][j][1] << "," << dp[i][j][2] << "," << "  ";
            }
            cout << endl;
        }
        */
        if(solve(0,0,N-1)) cout << "yes\n";
        else cout << "no\n";
    }
}

