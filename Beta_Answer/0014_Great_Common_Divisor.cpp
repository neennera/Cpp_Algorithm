#include<stdio.h>
int main(){
	int a,b,min;
	scanf("%d %d",&a,&b);
	if(a<=b)
		min=a;
	else
		min=b;
	int n=1;
	for(int i=1;i<=min;i++){
		if(a%i==0&&b%i==0)
			n=i;
	}
	printf("%d",n);
}

