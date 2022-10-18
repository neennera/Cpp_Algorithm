#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define MAX 200005

int N,M,u,v,ans = 0, ans_id = 0;
vector <list<int>> path(MAX);
int id=0, num[MAX], low[MAX];
stack <int> s;
bitset <MAX> current, vis;

void DFS(int u){
    num[u] = low[u] = id++;
    s.push(u);
    current[u] = 1;
    vis[u] = 1; //set vis here

    for(auto v: path[u]){
        if(!vis[v]) DFS(v); //change current to vis
        if(current[v]){
            low[u]= min(low[u],low[v]);
        }
    }

    //pop from stack if it start of cycly
    int count=0, min_id = u;
    if(num[u]==low[u]){
        while(1){
            int node=s.top(); s.pop();
            low[node]=low[u];
            current[node] = 0;
            count++; min_id=min(min_id,node);
            if(node==u) break;
        }
    }
    
    if(count > ans){
        ans=count;
        ans_id=min_id;
    }
}

void answer(){
    // map <int,int> m, m_id;

    // //COUNT EACH low_list
    // for(int i=1;i<=N;i++){
    //     m[low[i]]++;
    //     m_id[low[i]]=min(m_id[low[i]],i);
    // }

    // //find largest
    // for(auto x:m){
    //     if(x.second > ans){
    //         ans = x.second;
    //         ans_id = m_id[x.first];
    //     }
    // }

    //output
    cout << ans << "\n";
    //cout << ans_id << " ** ";
    for(int i=ans_id;i<=N;i++){
        if(low[i]==low[ans_id]){
            cout << i << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(low,0x3f,sizeof(low));

    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        path[u].push_back(v);
    }

    //SCC
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        DFS(i);
    }

    //ANSWER
    answer();
}