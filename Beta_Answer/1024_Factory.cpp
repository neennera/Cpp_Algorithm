#include<bits/stdc++.h>
using namespace std;

int N,u,sd,tr;
long long ans=LONG_MAX,a,b,c;
int ps[1005],mes[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(ps,0,sizeof(ps));
    cin >> N;
    cin >> ps[0];

    for(int i=1;i<N;i++){
        cin >> u;
        ps[i]=ps[i-1]+u;
    }

    for(int i=0;i<N-2;i++){
        a=ps[i];
        for(int j=i+1;j<N-1;j++){
            b=ps[j]-ps[i];
            c=ps[N-1]-ps[j];
            {
                mes[0]=a,mes[1]=b,mes[2]=c;
                sort(mes,mes+3);
            }
            if(abs(mes[2]-mes[0])<ans){
                ans=abs(mes[2]-mes[0]);
                sd=i+1;
                tr=j+1;
            }
        }
    }

    cout << sd+1 << " "<< tr+1;
}

