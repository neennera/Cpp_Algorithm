#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m=1,k;
    cin >> n;
    int a[10001];
    for(int i=1;i<=10001;i++){
        a[i-1]=0;
    }
    for(int i=0;i<n;i++){
        cin >> k;
        a[k-1]+=1;
        if(a[k-1]>a[m-1])
            m=k;
    }
     for(int i=1;i<=10001;i++){
        if(a[i-1]==a[m-1])
            cout << i << " ";
    }
}


