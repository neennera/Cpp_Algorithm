#include<bits/stdc++.h>
using namespace std;

string a,b;
queue <int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> b >> a;
    if(a.length()!=b.length()) cout << "R.I.P.";
    for(int i=0;i<a.length();i++){
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
        int n=b[i]-a[i];
        if(n<0) n+=26;
        //cout << n;
        if(n>=10){cout << "R.I.P."; return 0;}
        q.push(n);
    }
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
}
/*
x y z a b c
z z+9=i
i-z=
*/

