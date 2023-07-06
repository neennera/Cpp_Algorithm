#include<bits/stdc++.h>
using namespace std;

int N,u;
long long int ans;
priority_queue <int> a,b;
//priority_queue <int,vector<int>,greater <int>> b;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){cin >> u; a.push(u);};
    for(int i=0;i<N;i++){cin >> u; b.push(u);};
    while(!a.empty()){
        //cout << a.top() << " "<< b.top() << endl;
        ans+=abs(a.top()-b.top());
        a.pop(), b.pop();
    }
    cout << ans;
}

