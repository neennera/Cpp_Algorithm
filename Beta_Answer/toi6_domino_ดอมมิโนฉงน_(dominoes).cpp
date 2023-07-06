#include<bits/stdc++.h>
using namespace std;

int N;
//0=-- 1=||
int dom(int n,string a){
    if(n==N){
        for(auto i:a){
            if(i=='1'){
                cout << "||\n";
            }else{
                cout << "--\n";
            }
        }
        cout << 'E' << '\n';
    }
    if(n>=N) return 0;
    dom(n+1,a+"0");
    dom(n+2,a+"1");
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    string s="";
    dom(0,s);
}

