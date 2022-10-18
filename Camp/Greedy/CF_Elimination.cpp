#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int Q,a,b,c,d;

    cin >> Q;
    while(Q--){
        cin >> a >> b >> c >> d;
        cout << max(a+b,c+d) << "\n";
    }
}