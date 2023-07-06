#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 1

int N;
double a[2002];

int main(){
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0;i<N*2;i++) cin >> a[i];
    sort(a,a+(2*N));
    double ans=0;

    for(int i=0;i<N;i++){
        //cout << a[i] << " " << a[(N*2)-i-1] << "\n";
        ans+=(a[i]*a[(N*2)-i-1]);
    }

    printf("%.0f",ans);
    return 0;
}

