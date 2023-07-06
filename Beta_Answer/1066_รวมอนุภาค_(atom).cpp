#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> atom;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        atom.push_back(m);
    }
    int sum=0;
    while(atom.size()>1){
        int M=INT_MIN;
        int id;
        for(int i=0;i<atom.size()-1;i++){
            if(abs(atom[i]-atom[i+1])>M){
                M=abs(atom[i]-atom[i+1]);
                id=i;
            }
        }
        atom.erase(atom.begin()+id,atom.begin()+id+2);
        sum+=M;
    }
    cout << sum;
}

