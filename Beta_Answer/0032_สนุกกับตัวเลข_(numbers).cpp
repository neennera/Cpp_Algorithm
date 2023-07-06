#include<stdio.h>
#include<algorithm>
using namespace std;
int swap(int *x,int *y){
	int min=*y;
	*y=*x;
	*x=min;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n]={NULL};
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	/*for(int i=0;i<n-1;i++){
		int min=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]<min){
				swap(&a[i],&a[j]);
			}
		}
	}*/
	sort(a,a+n);
	int i=1;
	while(a[i-1]==0){
		i++;
	}
	//printf("%d",i);
	swap(&a[0],&a[i-1]);
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}

