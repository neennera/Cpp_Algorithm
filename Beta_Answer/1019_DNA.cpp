#include<bits/stdc++.h>
using namespace std;
int id=0,k=0,track=0;

int finds(char a[],char b[],int n,int m,int d){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            track=0;
            while(a[i+track]==b[j+track]&&a[i+track]!='\0'){
                track++;
                if(track>k){
                    k=track;
                    if(d==0){
                        id=i;
                    }else{
                        id=j;
                    }
                }
            }
        }
    }
}

int main(){
    char a[201],b[201];
    cin >> a >> b;
    if(strlen(a)>strlen(b)){
        finds(b,a,strlen(b),strlen(a),1);
        for(int i=id;i<id+k;i++){
            cout << a[i];
        }

    }else{
        finds(a,b,strlen(a),strlen(b),0);
        for(int i=id;i<id+k;i++){
            cout << a[i];
        }
    }
}

