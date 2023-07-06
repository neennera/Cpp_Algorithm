#include<bits/stdc++.h>
using namespace std;

int a[260],N;
int L=INT_MAX,R=INT_MIN,l,h,r;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N;
    memset(a,0,sizeof(a));
    for(int i=0;i<N;i++){
        cin >> l >> h >> r;
        for(int j=l;j<r;j++){
            a[j]=max(a[j],h);
        }
        L=min(l,L);
        R=max(r,R);
    }
    for(int j=L;j<=R;j++){
        cout << j << " ";
        while(a[j]==a[j+1]) j++;
        cout << a[j] << " ";
    }
}

