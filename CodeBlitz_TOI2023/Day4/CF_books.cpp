#include<bits/stdc++.h>
using namespace std;

int N, T, ans = 0;
vector <int> book;

int main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> T;
    for(int i=0;i<N;i++){
        int u; cin >> u;
        book.push_back(u);
    }

    int right=0;	
	for(int left=0;left<N;left++){
		while(right<N && T-book[right]>=0){
            T-=book[right];
            right++;
        }

		ans =max(ans, right-left);

		if(right==left){
            right++;
        }else{
            T+=book[left];
        }
	}
	cout << ans;
}