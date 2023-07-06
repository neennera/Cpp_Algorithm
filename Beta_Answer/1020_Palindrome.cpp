#include<bits/stdc++.h>
#include<string>
using namespace std;

string s;

int palin(int st, int ed){
    for(int i=0;i<(ed-st+1);i++){
        if(s[st+i]!=s[ed-i]) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> s;
    int N= s.length();
    int mid = N/2; 
    for(int i=0;i<N;i++) s[i]=tolower(s[i]);    
    
    
    if( palin(0,N-1) && palin(0,mid-1)){
        cout << "Double Palindrome";
    }else if(palin(0,N-1)){
        cout << "Palindrome";
    }else{
        cout << "No";
    }
}
