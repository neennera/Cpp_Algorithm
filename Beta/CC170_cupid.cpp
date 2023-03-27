#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second

int n,k;
pair<int,int>p[1005];

int main(){
    cin >> n >> k;
    for(int i=0; i<n ;i++){
        cin >> p[i].ft >> p[i].sd;
    }

    for(int i=0; i<n ;i++){

        // if can pair in town
        if(p[i].ft>p[i].sd){
            p[i].ft-=p[i].sd;
            p[i].sd=0;
        }
        else{
            p[i].sd-=p[i].ft;
            p[i].ft=0;
        }

        // check from nearest town
        for(int j=i+1; j<=min(i+k,n-1); j++){

            if(p[i].ft==0 && p[i].sd==0)
                break;

            // man in town and girl in another town
            int min1=min(p[i].ft,p[j].sd);
            p[i].ft-=min1;
            p[j].sd-=min1;

            // girl in town and man in another town
            int min2=min(p[i].sd,p[j].ft);
            p[i].sd-=min2;
            p[j].ft-=min2;
        }
    }

    for(int i=0; i<n; i++){
        if(p[i].ft>0 || p[i].sd>0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}