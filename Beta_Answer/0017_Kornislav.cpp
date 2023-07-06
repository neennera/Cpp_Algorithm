#include<stdio.h>

int sort(int *p){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(p[j]>p[j+1]){
				int m=p[j];
				p[j]=p[j+1];
				p[j+1]=m;
			}
		}
	}
}

int main(){
	int a[4];
	for(int i=0;i<4;i++)
		scanf("%d",&a[i]);
	sort(a);
	printf("%d",a[0]*a[2]);
}

