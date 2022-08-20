#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii 

int N,a;
int div7[50005];
vector <pair<int,int>> id;

void USA(){
    freopen("div7.in","r", stdin);
    freopen("div7.out","w", stdout);
}

int main(){
    USA();
    cin >> N;    
    for(int i=0;i<7;i++){
        id.push_back({N+1,0});
    }
    for(int i=1;i<=N;i++){
        cin >> a;
        div7[i]=(div7[i-1]+a)%7;
        id[div7[i]].ft=min(id[div7[i]].ft,i);
        id[div7[i]].sd=max(id[div7[i]].sd,i);
    }
    int ans=0;
    for(int i=0;i<7;i++){
        ans=max(ans,id[i].sd-id[i].ft);
    }
    cout << ans;
}