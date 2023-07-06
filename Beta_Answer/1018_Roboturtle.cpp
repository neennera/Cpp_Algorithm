#include<bits/stdc++.h>
using namespace std;

int main(){
    int d=0,x=0,y=0;
    char com[3];
    int n,m;
    bool check=false;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> com >> m;
        switch(com[0]){
            case 'F' : break;
            case 'R' : d+=1; break;
            case 'L' : d-=1; break;
            case 'B' : d+=2; break;
        }
        d=(d+4)%4;
        switch(d){
            case 0 : x+=m; break;
            case 1 : y-=m; break;
            case 2 : x-=m; break;
            case 3 : y+=m; break;
        }
        if(abs(x)>=50000||abs(y)>=50000){
            check=true;
        }
    }
    if(check){
        cout << "DEAD";
        return 0;
    }
    cout << x << " " << y << endl;
    switch(d){
        case 0 : cout << "E"; break;
        case 1 : cout << "S"; break;
        case 2 : cout << "W"; break;
        case 3 : cout << "N"; break;
    }

}

