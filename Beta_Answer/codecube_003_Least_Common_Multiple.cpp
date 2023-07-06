#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long A,B,ans;
    cin >> A >> B;
    cout << A*B/(__gcd(A,B));
}

