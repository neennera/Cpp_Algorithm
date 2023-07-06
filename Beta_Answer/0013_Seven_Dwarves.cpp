#include<stdio.h>

int main(){
	int a[9],m=0;
	for(int i=0;i<9;i++){
		scanf("%d",&a[i]);
		m=m+a[i];
	}
	
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if((m-a[i]-a[j])==100){
				a[i]=0;
				a[j]=0;
			}
		}
	}
	
	for(int i=0;i<9;i++){
		if(a[i]!=0)
			printf("%d\n",a[i]);
	}
}

