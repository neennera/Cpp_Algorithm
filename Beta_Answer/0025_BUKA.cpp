#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
	char a[100],b[100],op;
    cin >> a >> op >>b;
    int n=strlen(a),m=strlen(b);
    if(m>n){
        int k=m;
        m=n;
        n=k;
    }
    if(op=='+'){
        if(strcmp(a,b)==0){
            cout << 2;
            for(int i=0;i<n-1;i++)
                cout << 0;
        }else{
            cout << 1;
            for(int i=0;i<n-1;i++){
                if(i==(n-m-1))
                    cout << 1;
                else
                    cout << 0;
            }
        }
    }else{
        cout << 1;
        for(int i=0;i<((n-1)+(m-1));i++)
            cout << 0;
    }
}

