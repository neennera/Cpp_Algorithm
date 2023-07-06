#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n=s.length(),t=0,e=0,ele=0;
	for(int i=0;i<n;i++){
		t=t+s[i]-'0';
		ele = e*10+(s[i]-'0');
		e = ele%11;
	}
	cout << t%3 << " ";
	cout << e;
}

