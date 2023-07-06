#include<bits/stdc++.h>
using namespace std;

int N;
long long L,M,u,v;
int ps[1005],mes[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> v;
    L=v,M=v;
    for(int i=1;i<N;i++){
        cin >> u;
        L=L*u/__gcd(L,u);
        u=L;
        //M=temp;
        //cout << L << " ";
        swap(u,v);
    }
    cout << L;
}

