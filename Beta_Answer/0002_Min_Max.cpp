#include<stdio.h>
#include<iostream>
using namespace std;
int main (){
	int n;
	cin >> n;
	int a[n]={NULL};
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int M=a[0],m=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>M)
			M=a[i];
		if(a[i]<m)
			m=a[i];
	}
	printf("%d\n",m);
	printf("%d\n",M);
}

