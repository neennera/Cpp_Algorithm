#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

double think(int k){
    double ans=1;
    for(int i=0;i<(126*k)+3;i++){
        ans = ans *10;
    }
    ans = ans + 143;
    ans = ans / 127;
    return ans;
}

int main(){
    int k;
    cin >> k;
    double s=think(k);
    printf("%llf",s);
}