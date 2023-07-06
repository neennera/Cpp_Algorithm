#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define endll '\n'

map <int,ll> m;
vector <pair<ll,int>> f;
int c[7],ct=7;
string s;

bool compare(pair <ll,int> d1,pair <ll,int> d2){
    if(d1.ft==d2.ft)
        return d1.sd<d2.sd;
    return d1.ft>d2.ft;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for(int i=0;i<7;i++){
        f.push_back({0,i});
        c[i]=0;
    }

    while(1){
        cin >> s;
        if(s.compare("!")==0) break;

        for(int i=0;i<7;i++) m[i]=0;
        for(int i=0;i<s.length();i++)
            m[s[i]-'A']+=1;

        for(int i=0;i<7;i++){
            if(c[f[i].sd]) continue;
            f[i].ft+=m[f[i].sd];
        }
        sort(f.begin(),f.end());
        if(ct==1) continue;
        if(f[0].ft==f[1].ft) continue;
        f[0].ft=LONG_MAX;
        c[f[0].sd]=1;
        //printf("---- %c\n",f[0].sd+'A');
        ct--;
    }

    cout << ct << endl;
    sort(f.begin(),f.end(),compare);
    for(auto x:f){
        if(c[x.sd]) continue;
        printf("%c %lld\n", x.sd+'A', x.ft);
    }
    return 0;


}

