#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define tuu tuple<int, int, int, int, int, int>

int walk[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};
char m[205][205];
bool vis[205][205][7][128];
queue <tuu> q;
int N,M,ct=0,xx,yy;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s; cin >> s;
        for(int j=0;j<M;j++) {
            m[i][j]=s[j];
            if(m[i][j]=='S'){   //set start
                q.push({i, j, 1, 1, 0, 0});
                vis[i][j][1][0]=1;
            }else if(m[i][j]=='G'){ //set gem
                m[i][j]=('A'+(ct++));  //mark order of diff gem ABCDEFG
            }
        }
    }

    while(!q.empty()) {
        auto [x, y, time, time_m, gem_mask, gem_num] = q.front();
        q.pop();

        //Answer
        if(gem_num==7){
            cout << time-1;
            return 0;
        }

        time++;
        time_m=time%6 + ((time%6)==0 ? 6 : 0);
        // 1 2 3 4 5 6 1 2 3 4 5 6
        // 1 2 3 4 5 0 1 2 3 4 5 0
        
        for(int i=0;i<5;i++) {
            xx=x+walk[i][0];
            yy=y+walk[i][1];

            //Wall or Out
            if(xx<0||xx>=N||yy<0||yy>=M) continue;
            if(m[xx][yy]=='#'||vis[xx][yy][time_m][gem_mask]) continue;

            //number space
            if(m[xx][yy]>='1'&&m[xx][yy]<='6'){
                int number=m[xx][yy]-'0';
                if((time_m!=number)&&(gem_num<number)) continue;

                vis[xx][yy][time_m][gem_mask]=1;
                q.push({xx, yy, time, time_m, gem_mask, gem_num});
                continue;
            }

            //GEM
            if(m[xx][yy]>='A'&&m[xx][yy]<='G') {
                pair <int,int> temp={gem_mask,gem_num};

                // gem_mask&(1<<(m[xx][yy]-'A'))
                // 1001 & 1000 = 1000 :: if same it will be >1 -> we not repeating collect
                if(!(gem_mask&(1<<( m[xx][yy]-'A' )))){
                    temp.first |= (1 << (m[xx][yy]-'A'));   //new gem_mask
                    temp.second++;  //new gem_num
                }

                vis[xx][yy][time_m][temp.first]=1;
                q.push({xx, yy, time, time_m, temp.first, temp.second});
                continue;
            }

            //Free Space
            vis[xx][yy][time_m][gem_mask]=1;
            q.push({xx, yy, time, time_m, gem_mask, gem_num});
        }
    }
    cout << -1;
}
