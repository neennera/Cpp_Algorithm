#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define ll long long
#define pii pair<int,int>

int N,Q,M;
map <int,int> mem;
map <int,int> on;

int main(){
    //ios_base::sync_with_stdio(0), cin.tie(0);


    cin >> N >> Q >> M;
    for(int i=0;i<N;i++){
        cin >> mem[i];
    }
    priority_queue <pii> pq;
    while(Q--){
        int x;  cin >> x;
        --x;
        if(on[x]){
            on[x]++;
            pq.push({Q,x});
            continue;
        }
        while(M<mem[x]&&!pq.empty()){
            auto [time,number] =pq.top(); pq.pop();
            //cout << time << " : " << number << "\n";
            if(--on[number]==0){
                M+=mem[number];
            }
        }

        on[x]++;
        M-=mem[x];
        pq.push({Q,x});

        //cout << M << "\n";
    }

    cout << M;
}
