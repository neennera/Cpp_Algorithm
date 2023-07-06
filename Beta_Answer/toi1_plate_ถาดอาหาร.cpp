#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<int,int>
#define db 0

int N,M,c,id;
map <int,int> m;
char op;
vector <pii> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> c >> id;
        m[id]=c;
    }
    while(1){
        cin >> op;
        if(op=='X'){
            cout << 0 << "\n"; return 0;}
        if(op=='D'){
            if(q.empty()) cout << "empty\n";
            else{
                cout << q[0].sd << "\n";
                q.erase(q.begin());
            }
        }
        if(op=='E'){
            cin >> id;
            c=m[id];

            if(q.empty()){
                q.push_back({c,id});
                continue;
            }

            int it=0;
            while(q[it].ft!=c&& it!=q.size()){it++;}

            if(it==q.size()){        //no room
                q.push_back(make_pair(c,id));
            }else{
                while(q[it].ft==c&& it!=q.size()){it++;}
                //it--;
                q.insert(q.begin()+it,{c,id});
            }
        }

        //for(auto x:q) cout << x.sd << " ";
        //cout << "end\n";
    }

}
/*
2 6
1 41
1 42
1 43
2 201
2 202
2 203
E 41
E 201
D
E 202
E 42
E 43
D
E 203
D
D
D
X
*/

