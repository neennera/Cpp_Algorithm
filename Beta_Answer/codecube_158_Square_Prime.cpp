#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

// from stagement : ans is prime * prime
// sol : fine prime in range [2,1000] since 1000**2 = 1000000
// if it prime : ansrk sqare prime

bitset <1000005> ans; // sqare prime
int s,e;

bool ifPrime(int n){
	if (n<=1) return 0;
	if (n==2) return 1;
	if (n%2==0) return 0;

	for (int i=3; i<=sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;

}

int main(){	
	bool check=true;
	
	cin >> s >> e;

	for(int i=2; i<=1000; i++){
		bool prime=ifPrime(i);
		if(prime) ans[i*i]=true; 
	}


	for(int i=s; i<=e; i++){
		if(ans[i]){
			printf("%d ", i);
			check=false;
		}
	}

	if(check) cout << "-1";
	return 0;
}
