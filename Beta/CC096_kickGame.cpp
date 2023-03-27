#include <bits/stdc++.h>
#define st first
#define nd second
#define ll long long

using namespace std;

int n;
int a[300005], ans[100005];
ll qs[300005];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    cin >> n;

    // Create circle in array form like  1234 -> 123412341234
    // We set middle to a standard index thus we can quick sum from left of i and right of i easily
    // since it circle we can assume 3 round of index will enough


    for(int i=n+1; i<=2*n; i++) cin >> a[i];
    for(int i=n+1; i<=2*n; i++) cin >> qs[i];

    //Set value
    for(int i=1; i<=n ;i++){
        qs[i]=qs[n+i];          //left side
        qs[(2*n)+i]=qs[n+i];    // right
    }

    //make quick sum
    for(int i=1; i<=3*n; i++) qs[i]+=qs[i-1];

    //find answer by b-search
    for(int i=n+1; i<=2*n; i++){
        int s=0, e=(n-1)>>1;    // half of circle
        int maxx=0;

        while(s<=e){
            int mid=(s+e)>>1;
            int defend=qs[i+mid]-qs[i-mid-1]-(qs[i]-qs[i-1]);
            // qs[i+mid] - qs[i-mid-1]  = quick sum of select range
            // qs[i]-qs[i-1]       = delete a[i] value

            if(defend<=a[i]){
                maxx=max(maxx,2*mid);
                s=mid+1;
            }
            else e=mid-1;
        }
        ans[i-n]=maxx;
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}
