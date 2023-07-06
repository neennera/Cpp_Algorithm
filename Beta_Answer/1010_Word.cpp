#include<bits/stdc++.h>
using namespace std;
int N=0,M=0;
char t[25][25]={NULL};
int x[8]={-1,0,1,-1,1,-1,0,1};
int y[8]={-1,-1,-1,0,0,1,1,1};

int f2(char s[16],int n,int i,int j,int p){
    if(i>=N||i<=-1||j>=M||j<=-1)
        return false;
    if(n==strlen(s))
        return true;
    if(s[n]==t[i+y[p]][j+x[p]]){
        f2(s,n+1,i+y[p],j+x[p],p);
    }
    else
        return false;
}

int f1(){
    char s[16]={NULL};
    scanf("%s",&s);
    for(int j=0;j<strlen(s);j++)
        s[j]=tolower(s[j]);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            /*Check*/
            if(s[0]==t[i][j]){
                if(strlen(s)==1){
                    cout << i << " " << j << endl;
                    i=N; j=M;
                }
                /*find key*/
                for(int p=0;p<8;p++){
                    if(s[1]==t[i+y[p]][j+x[p]])
                        if(f2(s,2,i+y[p],j+x[p],p)){
                            cout << i << " " << j << endl;
                            p=8; i=N; j=M;
                        }
                }
                /*find key*/
            }
            /*Check*/
        }
    }
}

int main(){
    scanf("%d %d",&N,&M);
    char c;
    int g;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> c;
            t[i][j]=tolower(c);
        }
    }
    scanf("%d",&g);
    for(int i=0;i<g;i++){
        f1();
    }
}

