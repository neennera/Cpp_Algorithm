#include<bits/stdc++.h>
using namespace std;

int c(int a[]){
    for(int i=0;i<3;i++){
        int j=i;
        while(a[j-1]>a[j]&&j>0){
            int k=a[j];
            a[j]=a[j-1];
            a[j-1]=k;
            j--;
        }
    }
}

int main(){
    int a[3];
    for(int i=0;i<3;i++)
        cin >> a[i];
    c(a);
    char c[4];
    cin >> c;
    for(int i=0;i<3;i++){
        cout << a[c[i]-'A'] << " ";
    }
}

