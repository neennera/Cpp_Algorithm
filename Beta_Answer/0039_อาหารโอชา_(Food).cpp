#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int check(int j,int *p,int m);
int use[9]={NULL};

int dfs(int id,int n,int *ans,int *p,int m){
	if(id==n){
		for(int i=0;i<n;i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	else{
		for(int i=1;i<=n;i++){
			if(id==0&&check(i,p,m)){
				continue;
			}
			else{
				if(use[i]!=1){
				use[i]=1;
				ans[id]=i;
				dfs(id+1,n,ans,p,m);
				use[i]=0;
				}
			}
		}
	}
}

int check(int j,int *p,int m){
	for(int i=0;i<m;i++){
		if(j==p[i]){
			return true;
		}
	}
	return false;
}

int main(){
	int n,m;
	cin >> n >> m;
	int p[m];
	for(int i=0;i<m;i++)
		cin >> p[i];
	sort(p,p+m);
	int ans[n]={NULL};
	dfs(0,n,ans,p,m);
}

