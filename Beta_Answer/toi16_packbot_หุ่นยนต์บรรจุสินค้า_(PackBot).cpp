#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define pii pair<double,int>
#define db 0
stack <ll> item, op;
ll ans=0;
double cost[]={0.04,0.08,0.16};
ll item1,item2;
int ope;
string s;
ll cc(){
    //return cost[ope-1]*(double)(item1+item2);
    return (item1+item2) + cost[ope-1]*(double)(item1+item2);
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    char c;
    for(int i=0;i<s.size();i++){
        c=s[i];
        if(c>='A'&&c<='Z'){item.push(20);}
        else if(c=='['){op.push(4);}
        else if(c==']'){
            while(op.top()!=4){
                item2=item.top(); item.pop();
                item1=item.top(); item.pop();
                ope=op.top(); op.pop();
                item.push(cc());
            }
            op.pop();
        }else{
            c-='0';
            while(!op.empty()&&c<=op.top()){
                if(op.top()==4) break;
                item2=item.top(); item.pop();
                item1=item.top(); item.pop();
                ope=op.top(); op.pop();
                item.push(cc());
            }
            op.push(c);
        }
    }
    while(!op.empty()){
        item2=item.top(); item.pop();
        item1=item.top(); item.pop();
        ope=op.top(); op.pop();
        item.push(cc());
    }
    cout << item.top();
}

