#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int POW(int n);

long double n[440];
int main(){
    int q;
    long double b=1;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%llf",&n[i]);
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<n[i];j++){
            b = b*2;
        }
    printf("%.0llf\n",b);
    b = 1;
    }
    return 0;
}
int POW(int n){
	char a[100]={NULL};
	if(n==0){
		cout << '1';
		return 0;
	}else{
	int i,m=1;
	a[0]='1';
	while(m<=n){
		i=0;
		int len=strlen(a);
		while(i<len){
			int id=i,c;
			c=(a[i]-'0')*2;
			if(c>9){
				do{
					a[id]='0'+(c%10);
					if(a[id+1]<'0'||a[id+1]>'9')
						a[id+1]='1';
					else a[id+1]=a[id+1]+1;
					id++;
				}while(a[id]>'9');
			}else{
				a[id]='0'+c;
			}
			i++;
		}
		m++;
	}
	
	for(int i=strlen(a)-1;i>=0;i--){
		cout << a[i];
		}
	}
	cout << endl;
}
	

