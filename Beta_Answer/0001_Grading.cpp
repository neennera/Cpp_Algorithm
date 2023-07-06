#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int s=a+b+c;
	if(s>=80)
		printf("A");
	if(s<50)
		printf("F");
	switch(s/5){
		case 15:
			printf("B+");
			break;
		case 14:
			printf("B");
			break;
		case 13:
			printf("C+");
			break;
		case 12:
			printf("C");
			break;
		case 11:
			printf("D+");
			break;
		case 10:
			printf("D");
			break;
	}
}

