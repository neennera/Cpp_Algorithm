#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<ll,int>
#define db 0

struct DATA{
    double m,c;
    bool operator < (const DATA & d2) const{
        if(c==d2.c) return m > d2.m;
        return c<d2.c;
    }
};

int N;
double m,c;
vector <DATA> a;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> m >> c;
        a.push_back({m,c});
    }

    sort(a.begin(),a.end());

    double ans=0, m_ans=0, c_ans=0;
    double m=0,c=0;
    for(int i=0;i<N;i++){
        m+=a[i].m;
        c=a[i].c;

        if((m)/(c)>ans){
            m_ans=m;
            c_ans=c;
            ans=m_ans/c_ans;
        }
    }

    //cout << m_ans << " " << c_ans;
    printf("%.0lf %.0lf",m_ans,c_ans);
}

