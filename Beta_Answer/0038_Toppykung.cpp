#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;
int swap(char a[32],char b[32]){
	char x[31];
	strcpy(x,a);
	strcpy(a,b);
	strcpy(b,x);
}
int sort(char s[][32],int n){
	bool check;
	do{
		check=false;
		for(int i=0;i<n-1;i++){
			if(strcmp(s[i],s[i+1])>0){
				swap(s[i],s[i+1]);
				check=true;
			}
		}
		n--;
	}while(check);
}
int check(char s[][32],char a[32],int n){	//check again
	for(int i=0;i<n;i++){
		//for(int j=0;j<n;j++){
			if(strcmp(s[i],a)==0)
				return false;
		//}
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	char s[n][32],a[32];
	for(int i=0;i<n;i++){
		cin >> a;
		if(check(s,a,sizeof(s)/sizeof(s[0]))){
			strcpy(s[i],a);
		}else{
			i=i-1;
			n=n-1;
		}
	}
	sort(s,n);
	for(int i=0;i<n;i++){
		cout << s[i] << endl;
	}
}

