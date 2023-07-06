#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin >> n;
	cin >> m;
	int x[n][m],y[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> x[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> y[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << x[i][j]+y[i][j];
			printf(" ");
		}
		printf("\n");
	}
}

