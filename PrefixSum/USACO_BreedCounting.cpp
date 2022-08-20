#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int a,b,c;
struct cow{
    int a=0,b=0,c=0;
};

void USA(){
    freopen("bcount.in","r", stdin);
    //freopen("bcount.out","w", stdout);
}

int main(){
    USA();
    int N,Q;    cin >> N >> Q;
    struct cow c[N+2];
    c[0]={0,0,0};
    for(int i=1;i<=N;i++){
        cin >> a;
        c[i].a = c[i-1].a + (a==1);
        c[i].b = c[i-1].b + (a==2);
        c[i].c = c[i-1].c + (a==3);
    }
    for(int i=0;i<Q;i++){
        cin >> a >> b;
        cout << c[b].a-c[a-1].a << " ";
        cout << c[b].b-c[a-1].b << " ";
        cout << c[b].c-c[a-1].c << "\n";
    }
}
/*
6 3
2
1
1
3
2
1
1 6
3 3
2 4
*/