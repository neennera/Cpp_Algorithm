#include<bits/stdc++.h>
using namespace std;
 
int N, NX ,s,f;
map <int,int> m;
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin >> N;
    for( int i=0 ; i<N ; i++){
        cin >> s >> f;
        m[s]+=1, m[f+1]-=1;
        NX=max(NX,f);
    }
 
    int data[N], temp=0;
    for(int i=1;i<NX;i++){
        temp+=m[i];
        data[i]=temp;
        cout << data[i] << " ";
    }
 
    return 0;
}