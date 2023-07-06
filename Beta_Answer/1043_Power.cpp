#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 1

int N,u;
double temp,r,c;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    while(N--){
        cin >> u;
        for(r=27;r>1;r--){
            temp=pow(u,1.0/r);
            c=temp-floor(temp);
            if(c<0.000000001||c>0.99999999){
                cout<<  r << endl;
                r=-1;
            }
        }
        if(r==1)
            cout << "NO" <<endl;
    }
}


