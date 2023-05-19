#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

int N,c;
int ans=0;
bool cow[12][12];

bool flip(int x,int y){
    if (cow[x][y]) {
		for (int i=0; i<=x;i++) {
			for (int j=0;j<=y;j++){
                cow[i][j] = !cow[i][j];
            }
		}
		return true;
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
    cin >> N;
    string s;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int j=0;j<N;j++){
            cow[i][j]=s[j] - '0';
        }
    }

    int i=N-1,j=N-1;
    while(i>=0&&j>=0){
        ans += flip(i,j);
        
		if (j > 0) {
			j--;
		} else {
			i--;
            j=N-1;
		}
    }
    cout << ans;
}