#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x[n],y[n];
	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];
	float max=0,area;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				area=abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i])/2.00;
				if(area>max)
					max=area;
			}
		}
	}
	printf("%.3f",max);
}

