#include<bits/stdc++.h>
using namespace std;

int check(char a,char b){
    switch(a){
        case ('(') : if(b==')') return 1; break;
        case ('{') : if(b=='}') return 1; break;
        case ('[') : if(b==']') return 1; break;
    }
    return 0;
}
void f(){
    stack<char> s;
    string s1;
    cin >> s1;
    int i=0,n=s1.length();
    while(i<n){
        if(s.empty()){
            s.push(s1[i]);
            i++;
            continue;
        }
        if(check(s.top(),s1[i])){
            s.pop();
        }
        else{
            s.push(s1[i]);
        }
        i++;
    }
    cout << (s.empty() ? "yes" : "no" ) << endl;
}

int main(){
    int n;
    cin >> n;
    while(n){
        f();
        n--;
    }
}

