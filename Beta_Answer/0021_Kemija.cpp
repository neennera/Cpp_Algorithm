#include<stdio.h>
#include<string.h>

int check(char *p,int i){
	bool a=false;
	if(p[i+1]=='p'){
		if(p[i]==p[i+2]){
			switch (p[i]){
			case 'a':	return true; break;
			case 'e':	return true; break;
			case 'i':	return true; break;
			case 'o':	return true; break;
			case 'u':	return true; break;
			default:
				return false; break;
			}
		}
		else
			return false;
		
	}
	else{
		return false;
	}
}

int main(){
	char s[100];
	int i=0;
	while(s[i-1]!='\n'){
		scanf("%c",&s[i]);
		i++;
	}
	for(int i=0;i<strlen(s)-1;i++){
		if(s[i]==NULL)
			break;
		if(check(s,i)){
			printf("%c",s[i]);
			i+=2;
		}else{
			printf("%c",s[i]);
		}
	}
}

