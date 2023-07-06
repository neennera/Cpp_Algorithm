#include<bits/stdc++.h>
using namespace std;
#define ll long long

void USA(){
    freopen("div7.in","r", stdin);
    freopen("div7.out","w", stdout);
}

int N,K;
ll a[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    memset(a,0,sizeof(a));
    a[0]=1;
    int m=0;
    for(int i=1;i<=N;i++){
        m+=a[i-1]; //add on
        if(i-K>0){m-=(a[i-K-1]);} //non cross-> not do //drop off
        a[i]=m%2009;
        //cout << a[i] << " ";
    }
    //cout << endl;
    cout << a[N];
}

