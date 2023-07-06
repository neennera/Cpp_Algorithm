#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n==1)
		printf("%.6f",float(2));
	else if(n%2==0){
		printf("%.6f",n*1.0);
	}else if(n==3){
		printf("%.6f",2+sqrt(3));
	}
	else
		printf("%.6f",(n-5)+(2+2*sqrt(3)));
	
}

