#include<stdio.h>
#include<stdlib.h>
int main(){
	char *a;
	a=(char*)malloc((10001)*sizeof(char));
	scanf("%s",a);
	scanf("s",a);
	if(a[0]<=122&&a[0]>=97){
		for(int i=0;i<(sizeof(a)/sizeof(char));i++){
			if(a[i]==NULL){
				break;
			}
			if(a[i]>122||a[i]<97){
				printf("Mix");
				return 0;
			}	
		}
		printf("All Small Letter");
		return 0;
	}
	if(a[0]<=90&&a[0]>=65){
		for(int i=0;i<(sizeof(a)/sizeof(char));i++){
			if(a[i]==NULL){
				break;
			}
			if(a[i]>90||a[i]<65){
				printf("Mix");
				return 0;
			}	
		}
		printf("All Capital Letter");
		return 0;
	}
	free(a);
}

