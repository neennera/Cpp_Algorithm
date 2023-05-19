#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
 
 
int N,X;
vector <pair<int,int>> v;
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
 
    cin >> N >> X;
    for(int i=1;i<=N;i++){
        int t;
        cin >> t;
        v.push_back(make_pair(t,i));
    }
    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        int l=0,r=N-1,p=X-v[i].ft;
        while(l!=r){
            if((l!=i)&&(r!=i)&&(v[l].ft+v[r].ft==p)){
                cout << v[i].sd << " " << v[l].sd << " " << v[r].sd << endl;
                return 0;
            }
            if(v[l].ft+v[r].ft<p){
                l++; }
            else{
                r--; }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}