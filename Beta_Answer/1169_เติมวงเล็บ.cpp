/*
TASK: wheel.cpp
LANG: C++
AUTHOR: Naphat Saereerak
Center: SSWIT
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
    string st;
    int i=0;
    cin >> st;
    while(i<st.length()){
        if(s.size()==0||!(s.top()=='('&&st[i]==')'))
            s.push(st[i]);
        else
            s.pop();
        i++;
    }
    cout << s.size();
}

