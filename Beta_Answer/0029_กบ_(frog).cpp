#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int x,y,n=0;
	cin >> x >> y;
	n=y/x;
	if(y%x!=0)
		n++;
	if(y<x)
		n=2;
	cout << n;
}

