#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
unordered_map<unsigned long long,bool>ma;
int q;
unsigned long long x;
bool ifPrime(unsigned long long  n){
	if (n<=1) return 0;
	if (n==2) return 1;
	if (n%2==0) return 0;
	for (int i=3; i<=sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void pre(){
    // X is very big, we can't check by loop
    // obsearb 1 : 2**63 - 1 requair only 64-size array to remember
    unsigned long long temp;
    int n=1;
    while(n<64){
        temp = pow(2,++n) - 1;
        if(!ifPrime(temp)) continue;
        cout << temp << "\n";
    }
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
    // pre(); return 0;
    
    cin >> q;
    // from pre
	ma[3]=1;
	ma[7]=1;
	ma[31]=1;
	ma[127]=1;
	ma[8191]=1;
	ma[131071]=1;
	ma[524287]=1;
	ma[2147483647]=1;
	ma[2305843009213693951]=1;
	while(q--){
		cin >> x;
		cout << (ma[x] ? "YES" : "NO") << '\n';
	}
}