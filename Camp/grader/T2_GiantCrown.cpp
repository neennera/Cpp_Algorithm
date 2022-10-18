#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>

int N,a[200005],ans,sum=0,MX=0;
int f[200005], b[200005];
vector <pii> front;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(f,0,sizeof(f)), memset(b,0,sizeof(b));
    
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];
        sum+=a[i];
        MX=max(MX,a[i]);
        f[a[i]]+=a[i];
    }


    ans=sum;
    if(a[N/2]==MX){ ans = sum-1; }
    cout << ans;
    return 0;
}