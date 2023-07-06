#include<bits/stdc++.h>
using namespace std;

int N;

int gen(int n,string a){
    if(n==N){
        string b;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='1') continue;
            b=a;
            b[i]='1';
            cout << a << " " << b << "\n";
        }
    }
    if(n>=N) return 0;
    gen(n+1,a+"0");
    gen(n+1,a+"1");
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    string s="";
    gen(0,s);
}

