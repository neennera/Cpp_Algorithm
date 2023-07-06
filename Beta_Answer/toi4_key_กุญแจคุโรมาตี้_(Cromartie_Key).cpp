#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define SQ sqrt(2)/2
#define SS cos(45*PI/180)

int N,M;
string k1,k2,s;
char ss[3]={NULL};

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N >> M;
    cin >> k1 >> k2 >> s;
    for(int i=0;i<M;i++){
        char c=s[i];
        for(int j=0;j<N;j++){
            ss[0]=k1[j];
            ss[1]=k2[j];
            ss[2]=c;
            sort(ss,ss+3);
            c=ss[1];
            //cout << c << " ";
        }
        cout << c;
    }
}

