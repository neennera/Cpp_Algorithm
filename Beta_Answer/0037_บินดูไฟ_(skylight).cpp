#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int N,M,C,L,K;
	cin >> N >> M >> L >> K >> C;
	int cost=0,num;
	for(int i=0;i<M*N;i++){
		cin >> num;
		cost=cost+num;
	}
	//int P=C/K+(C%K);		//cost of lest of K
	//cost=cost+(P*L);
	cost=cost+L*K*C;
	if(cost%C==0)
		cout << cost/C;
	else
		cout << cost/(C)+1;
}

