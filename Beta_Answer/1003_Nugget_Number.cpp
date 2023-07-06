#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a[205]={1};
    int n;
    cin >> n;
    if(n<6){
        cout << "no";
        return 0;
    }
    for(int i=6;i<=n;i++){
        if(a[i-6]==1) a[i]=1;
        if(a[i-9]==1) a[i]=1;
        if(a[i-20]==1) a[i]=1;
        if(a[i]==1)
            cout << i << endl;
    }
    /*if(a[n]==1)
        cout << "yes";
    else
        cout << "no";*/
}

