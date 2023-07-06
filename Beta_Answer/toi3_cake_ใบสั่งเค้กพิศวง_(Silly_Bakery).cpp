#include<bits/stdc++.h>
using namespace std;

int req[5]={0};
int cs[5]={8,6,4,2,1};
int ans=0,u,N,cake;
//8 6 4 2 1

int check(){
    for(int i=0;i<5;i++){
        if(req[i]>0){return true;}
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cin >> u; req[j]+=u;
        }
    }
    while(check()){
        ans++;cake=8;
        for(int i=0;i<5;i++){
            if(cake<cs[i]||req[i]==0) continue;
            u=min(cake/cs[i],req[i]);
            cake-=(u*cs[i]);
            req[i]-=u;
        }
        /*
        for(int i=0;i<5;i++) cout << req[i] << " ";
        cout << endl;
        */
    }
    cout << ans;
}

