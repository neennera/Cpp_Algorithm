#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft fiest
#define sd second

int N,i;
bitset <(int)1e7> a;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(i=2;N>0;i++){
        if(a[i]) continue;
        N--;
        //cout << i << " ";
        for(int j=i;j<=(int)1e7;j+=i){
            a[j]=1;
        }
    }
    cout << --i;
}

