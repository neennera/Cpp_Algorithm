#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 1

int N, M;
char c='A';

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << c++;
            if(c>'Z') c='A';
        }
        cout << "\n";
    }
}

