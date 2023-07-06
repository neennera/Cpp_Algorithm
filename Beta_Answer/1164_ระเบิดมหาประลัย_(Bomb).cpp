#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define mx 5005
#define pii pair<int,int>

struct DATA{
    int x,y,id;
    bool operator < (const DATA & d2) const{
        if(x==d2.x) return y<d2.y;
        return x<d2.x;
    }
};

int N,id;
ll x,y;
vector <DATA> dot;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        dot.push_back({-1*x,-1*y, i});
    }

    sort(dot.begin(),dot.end());
    ll ct=0;
    set <pii> ans;
    ll max_x=LLONG_MAX,max_y=dot[0].y,temp_y=dot[0].y;

    for(auto pt=dot.begin();pt!=dot.end();pt++){
        x=(*pt).x * -1;
        y=(*pt).y * -1;

        if(x<max_x){
            max_y=max(max_y,temp_y);
            temp_y=y;
            max_x=x;
        }

        if(y>=max_y){
            ans.insert({x,-1*y});
            temp_y = max(temp_y,(ll)y);
        }

    }

    for(auto [x,y]:ans){
        cout<< x << " " << -1*y << "\n";
    }


    //cout << ct;
}

