#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char a[n][m];
    int block[m],pblock[m],check[m];
    for(int i=0;i<m;i++){
        block[i]=-1;
        check[i]=0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            char x;
            cin >> x;
            if(x=='O'&&check[j]==0){
                block[j]=i;
                check[j]=1;
            }
            a[i][j]=x;
        }
    }

    for(int i=0;i<m;i++){
        cin >> pblock[i];
        while(pblock[i]>0&&(a[n-1][i]!='#'&&a[n-1][i]!='O')){
            a[block[i]+1][i]='#';
            block[i]++;
            pblock[i]--;
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}

