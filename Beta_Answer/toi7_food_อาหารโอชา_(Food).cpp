#include<bits/stdc++.h>
using namespace std;
int N,M,u;
set <int> dont;
int per(int a[],set <int> s,int n){
    if(n==N){
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    }
    for(int i=1;i<=N;i++){
        if(s.find(i)!=s.end()) continue;
        set <int> st;
        st=s;
        st.insert(i);
        a[n]=i;
        per(a,st,n+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++){cin >> u; dont.insert(u);};
    for(int i=1;i<=N;i++){
        if(dont.find(i)!=dont.end()) continue;
        set <int> st;
        int a[N]={0};
        st.insert(i);
        a[0]=i;
        per(a,st,1);
    }
}

