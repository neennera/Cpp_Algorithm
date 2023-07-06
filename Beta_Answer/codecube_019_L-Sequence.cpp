#include<bits/stdc++.h>
using namespace std;

vector <int> s;
int u,K,N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> u;
        s.push_back(u);
    }
    for(int i=0;i<K&&(!s.empty());i++){
        for(int j=0;j<s.size();j++){
            if(s[j]>s[j+1]||j==s.size()-1){
                s.erase(s.begin()+j);
                break;
            }
        }
    }
    for(auto x:s)
        cout << x << " ";
}

