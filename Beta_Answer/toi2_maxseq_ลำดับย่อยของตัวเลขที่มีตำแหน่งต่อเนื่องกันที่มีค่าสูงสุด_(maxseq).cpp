#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int N, a[2505];
ll ans=0,sd=0;
int st,ed,id;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    memset(a,0,sizeof(a));
    for(int i=1;i<=N;i++){
        cin >> a[i];
        if(sd+a[i]<a[i]){
            id=i;
            sd=a[i];
        }else{
            sd=sd+a[i];
        }
        if(sd>ans){
            ans=sd;
            st=id;
            ed=i;
        }
    }

    if(!ans){cout << "Empty sequence";}
    else{
        for(int i=st;i<=ed;i++) cout << a[i] << " ";
        cout << endl << ans;

    }
}

