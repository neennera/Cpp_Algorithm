#include<stdio.h>

int main(){
	int d,m;
	scanf("%d %d",&d,&m);
	int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<m-1;i++)
		d=d+month[i];
	d=d%7;
	switch(d){
		case 1 : printf("Thursday"); break;
		case 2 : printf("Friday"); break;
		case 3 : printf("Saturday"); break;
		case 4 : printf("Sunday"); break;
		case 5 : printf("Monday"); break;
		case 6 : printf("Tuesday"); break;
		case 0 : printf("Wednesday"); break;
	}
}

