#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0
int N,u,M;
int pa[102][42];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(pa,0,sizeof(pa));
    cin >> M >> u >> N;
    pa[0][u-1]=-1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            cin >> u;
            if(u==1){continue;}
            if(j-1>=0&&pa[i-1][j-1]!=0){ pa[i][j]=2;}
            else if(pa[i-1][j]!=0){ pa[i][j]=3;}
            else if(j+1<M&&pa[i-1][j+1]!=0){pa[i][j]=1;}
            //cout << pa[i][j] << " ";
        }
        //cout << endl;
    }
    int i=N;
    for(int j=0;j<M;j++){
        if(pa[N][j]!=0){
            vector <int> ans;
            while(pa[i][j]!=-1){
                ans.push_back(pa[i][j]);
                switch(pa[i][j]){
                    case 1 : j++; break;
                    case 2 : j--; break;
                    case 3 : break;
                }
                i--;
            }
            for(int i=ans.size()-1;i>=0;i--)
                cout << ans[i] << "\n";
            return 0;
        }
    }
}

