#include<bits/stdc++.h>
using namespace std;
int table[10][10],n;
int main(){
    cin >> n;
    int used[(int)pow(n,2)];
    for(int i=1;i<=pow(n,2);i++){
        used[i]=0;
    }
    bool c=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int m;
            cin >> m;
            table[i][j]=m;
            used[m]++;
            if(used[m]>1)
                c=true;
        }
    }
    if(c){
        cout << "No";
        return 0;
    }
    int m=0;
    for(int i=0;i<n;i++){
        m+=table[0][i];
    }
    int k;
    for(int i=1;i<n;i++){
        k=0;
        for(int j=0;j<n;j++){
            k+=table[i][j];
        }
        if(k!=m){
            cout << "No";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        k=0;
        for(int j=0;j<n;j++){
            k+=table[j][i];
        }
        if(k!=m){
            cout << "No";
            return 0;
        }
    }
    k=0;
    for(int i=0,j=0;i<n;i++,j++){
        k+=table[i][j];
    }
    if(k!=m){
        cout << "No";
        return 0;
    }
    k=0;
    for(int i=n-1,j=0;i>=0;i--,j++){
        k+=table[i][j];
    }
    if(k!=m){
        cout << "No";
        return 0;
    }
    cout << "Yes";
}

