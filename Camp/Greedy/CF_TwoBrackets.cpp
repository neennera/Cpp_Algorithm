#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int Q;
ll a,b,ans=0;
string s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> Q;
    while(Q--){
        ans=0, a=0, b=0;
        cin >> s;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(' : a++; break;
                case ')' : ans+=a; break;
                case '[' : b++; break;
                case ']' : ans+=b; break;
            }
        }

        cout << ans << "\n";
    }
}