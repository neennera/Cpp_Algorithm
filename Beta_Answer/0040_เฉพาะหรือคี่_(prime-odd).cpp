#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
/*bool primeC(int a){
	if(a%2==0||(a==1)){
			return false;
		}else if(a==2){
			return true;
		}else{	
		for(int j=2;j<=a;j++){
			if(j==a){
				return true;
			}else if(a%j==0){
					return false;
				}	
			}
	}
}*/
int main(){
	int n;
	cin >> n;
	string a;
	bool odd;
	for(int i=0;i<n;i++){
			odd=false;
			cin >> a;
			int m = a.length();
			if(a=="2")
				odd=true;
			switch(a[m-1]){
				case '1':
				case '3':
				case '5':
				case '7':
				case '9':
					odd=true; break;
			}
			if(odd)
				cout << "T" << endl;
			else
				cout << "F" << endl;
	}
}

