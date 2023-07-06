#include<stdio.h>

int main(){
	int score[5]={},s;
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&s);
			score[i]=score[i]+s;
		}
	}
	/*for(int i=0;i<5;i++){
		printf("\n%d %d",i+1,score[i]);
	}*/
	int max=score[0],win=0;
	for(int i=0;i<5;i++){
		if(score[i]>max){
			win=i;
			max=score[i];
		}
	}
	printf("%d %d",win+1,max);
}

