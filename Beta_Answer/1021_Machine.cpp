#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0


int N,u;
char c;
priority_queue <int> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> c;
        if(c=='Q'){
            if(q.empty()) cout << -1 << "\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }else{
            cin >> u;
            q.push(u);
        }
    }

}

