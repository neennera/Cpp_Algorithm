#include<bits/stdc++.h>
using namespace std;

int ord[5]={0};

int main(){
    int n,a;
    scanf("%d",&n);
    while(n--){
        for(int i=0;i<5;i++){
            scanf("%d",&a);
            ord[i]+=a;
        }
    }
    cout << ord[0]+ (6*ord[1]+4*ord[2]+2*ord[3]+ord[4]+7)/8;
}

