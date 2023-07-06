#include<iostream>
#include<math.h>
using namespace std;

unsigned long long f(int n){
	if(n<=0)
		return 1;
	else
		return n*f(n-1);
}

int main(){
	int n,m;
	unsigned long long int a=1;
	cin >> n;
	m=n/2;
	/*if(m==0){
		cout << 1;
		return 0;
	}*/
		
	for(int i=n;i>m;i--){
		a=a*i;
	}
	if(n%2==0)
		a=a/f(m);
	else
		a=a/f(m+1)*2;	//cause it had to switch
	cout << a;
}

