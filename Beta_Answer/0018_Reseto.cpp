#include<stdio.h>

int s=0;


int main(){
	int n,k,s=0;
	scanf("%d %d",&n,&k);
	int num[n];
	for(int i=0;i<n;i++)
		num[i]=0;
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(((j+1)%(i+1)==0)&&num[j]==0){
				s++;
				num[j]=1;
			}
			if(s==k){
				printf("%d",j+1);
				return 0;
			}
		}
	}
}

