#include<bits/stdc++.h>
using namespace std;
#define ll long long

int Q;
ll a[4];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> Q;
    while(Q--){
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a,a+4);
        cout << a[0] * a[2] << "\n";
    }
}