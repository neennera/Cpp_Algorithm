#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,w,s,k=0;
    while(true){
        cin >> n;
        if(n<0)
            break;
        w=1,s=0,k=0;
        for(int i=1;i<=n;i++){
            k=w;
            w=w+1+s;
            s=k;
        }
        cout << w << " "  << w+s+1 << endl;
    }
}

