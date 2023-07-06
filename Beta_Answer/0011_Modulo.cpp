#include<bits/stdc++.h>
using namespace std;

int main(){
    set <int,greater<int>> x;
    for(int i=0;i<10;i++){
        int n;
        cin >> n;
        x.insert(n%42);
    }
    cout << x.size();
}

