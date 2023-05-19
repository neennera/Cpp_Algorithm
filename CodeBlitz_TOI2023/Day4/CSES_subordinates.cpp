#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
 
int N,u,v, child[200005];
vector <list<int>> path(200005);
 
int sol(int u){
    int temp=0;
    for(auto v:path[u]){
        temp+=sol(v);
    }
    child[u]=temp;
    return temp + 1;
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
 
    cin >> N;
    for(int i=2;i<=N;i++){
        cin >> u;
        path[u].push_back(i);
    }
 
    sol(1);
 
    for(int i=1;i<=N;i++) cout << child[i] << " ";
}