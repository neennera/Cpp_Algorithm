#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,K;
ll ans;
ll v[10005];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;
    memset(v,0,sizeof(v));
    ll u,t;
    for(int i=0;i<=2*N;i++){
        if(i%2==0){
            for(int j=0;j<N;j++){
                cin >> u;
                if(i>0){
                    v[(((i/2)-1)*N)+j]-=(3*u);
                }
                if(i<2*N){
                    v[((i/2)*N)+j]+=(3*u);
                }
            }
        }else{
            cin >> t;
            for(int j=0;j<N;j++){
                cin >> u;
                v[((i/2)*N)+j]+=(5*t);
                v[((i/2)*N)+j]-=(5*u);
                t=u;
            }
        }
    }

    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << v[(i*N)+j] << " ";
        }
        cout << endl;
    }
    */

    sort(v, v+(N*N));
    for(int i=0;i<K;i++){
        ans+=v[i];
        //cout << v[i] << " ";
    }
    cout << ans;
}



