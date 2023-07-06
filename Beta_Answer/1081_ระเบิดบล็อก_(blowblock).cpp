#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,u;
vector <int> a1,a2,a3,a4;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> u;
            if(i%2==0&&j%2==0) a1.push_back(u);
            if(i%2==0&&j%2==1) a2.push_back(u);
            if(i%2==1&&j%2==0) a3.push_back(u);
            if(i%2==1&&j%2==1) a4.push_back(u);
        }
    }

    sort(a1.begin(),a1.end(),greater<int>());
    sort(a2.begin(),a2.end(),greater<int>());
    sort(a3.begin(),a3.end(),greater<int>());
    sort(a4.begin(),a4.end(),greater<int>());

    int mn=a1.size();
    int K=(N/4)*4,i=0;
    ll ans=0;
    while(i<mn){
        ans+=a1[i]*a2[i]*a3[i]*a4[i];
        //cout << a1[i]*a2[i]*a3[i]*a4[i] << '\n';
        i++;
    }
    cout << ans;
}

