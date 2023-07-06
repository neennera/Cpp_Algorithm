#include<bits/stdc++.h>
using namespace std;

int N,B,ct=0;

int prime(int n){
    if(n%2==0&&n!=2) return 0;
    if(n==3) return 1;
    for(int i=3;i<sqrt(n)+1;i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> B;
    for(int i=2;i<=N;i++){
        if(prime(i)){ct++;}
    }
    cout << max(0,ct-B);
}


