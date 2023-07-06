#include<bits/stdc++.h>
using namespace std;
int a[17][17];
int m=0,n;
int u;
int p();
int ser(int i,int j,int k){
    a[i][j]=0;
    u+=1;
    if(a[i][j+1]==k&&j<n-1){
        ser(i,j+1,k);
    }
    if(a[i][j-1]==k&&j>0){
        ser(i,j-1,k);
    }
    if(a[i+1][j]==k&&i<n-1){
        ser(i+1,j,k);
    }
    if(a[i-1][j]==k&&i>0){
        ser(i-1,j,k);
    }
}

int check(int i,int j,int k){
    if(a[i][j+1]==k&&a[i][j+2]==k)
        return false;
    if(a[i+1][j]==k&&a[i+2][j]==k)
        return false;
    return true;
}

int p(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout <<  a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    bool c;
    do{
        c=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=0){
                    bool d=check(i,j,a[i][j]);
                    u=0;
                    ser(i,j,a[i][j]);
                    if(u==3&d)
                        m++;
                    c=true;
                    //p();
                }
            }
        }
    }while(c);
    cout << m;
}

