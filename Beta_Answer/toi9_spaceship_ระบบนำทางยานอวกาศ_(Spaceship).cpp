#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

#define tp tuple<int, int, int, int, int, int> // x,y,z,m,k,c

int N,M;
int ans=INT_MAX;
bool vis[15];
vector <tp> s; // station : x,y,z,m,k,c

int dist(tp a,tp b){
    auto [x1,y1,z1,m1,k1,c1] = a;
    auto [x2,y2,z2,m2,k2,c2] = b;
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}

void DFS(int u, int d, int m, int k, int c){
    if(min({m,k,c}) >= N){ ans = min(ans,d); return;}
    
    vis[u]=1;

    for(int v=0;v<=M;v++){  //beware : i<=M
        if(vis[v]) continue;

        auto [xx,yy,zz,mm,kk,cc] = s[v];

        vis[v]=1;
        DFS(v, d+dist(s[u],s[v]), m+mm, k+kk, c+cc);
        vis[v]=0;
    }
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int nx,ny,nz,nm,nk,nc;
    cin >> N;
    cin >> nx >> ny >> nz;
    s.push_back({nx, ny, nz, 0, 0, 0});
    
    cin >> M; // M <=10 : can permutations
    for(int i=0;i<M;i++){
        cin >> nx >> ny >> nz >> nm >> nk >> nc;
        s.push_back({nx, ny, nz, nm, nk, nc});
    }

    DFS(0,0,0,0,0);
    cout << ans;
}
