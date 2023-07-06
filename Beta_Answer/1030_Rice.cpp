#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<double,int>
#define db 0

int N,Q;
double u,c;
priority_queue <pii> q;
ll temp=0;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> u >> c;
        //v.push_back({u/c,c});
        q.push({-1*u/c,c});
    }

    double ct,p;
    double ans;
    cin >> Q;
    while(Q--){
        cin >> ct;
        ans=0;
        while(ct){
            u=q.top().ft;
            c=q.top().sd;
            q.pop();

            p=min(ct,c);
            ct-=p;
            c-=p;
            ans+=-1*p*u;
            if(c){
                q.push({u,c});
            }
        }

        printf("%.3f\n",ans);
    }
}

