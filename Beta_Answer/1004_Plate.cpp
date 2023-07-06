#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map <int,int> lis;
vector <pii> q;

int f1(){
    int id,cl=0;
    cin >> id;
    cl=lis[id];
    if(q.empty()){
        q.push_back(pii(cl,id));
    }else{
        int i=q.size()-1;
        for(;i>=0;i--){
            pii s=q[i];
            if(s.first==cl){
                q.insert(q.begin()+i+1,pii(cl,id));
                //cout << "     " << i << endl;
                return 0;
            }
        }
        q.push_back(pii(cl,id));
    }
}

int f2(){
    if(q.empty()){
        cout << "empty\n";
        return 0;
    }
    pii s=q.front();
    q.erase(q.begin());
    printf("%d\n",s.second);
}

int main(){
    int c,s,id,cl;
    cin >> c >> s;
    for(int i=0;i<s;i++){
        scanf("%d %d",&cl,&id);
        lis.insert(pii(id,cl));
    }
    int p=1;
    while(p==1){
        char c;
        cin >> c;
        switch(c){
            case 'E' :f1(); break;
            case 'D' :f2(); break;
            default : p=0;
        }
    }
    cout << 0;
}

