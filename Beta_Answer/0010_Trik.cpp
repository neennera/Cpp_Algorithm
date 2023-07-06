#include<bits/stdc++.h>
using namespace std;

int s(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}

int main(){
    int a[3]={1,0,0};
    char c[52];
    cin >> c;
    for(int i;c[i]!=NULL;i++){
        switch(c[i]){
        case 'A' : s(&a[0],&a[1]); break;
        case 'B' : s(&a[1],&a[2]); break;
        case 'C' : s(&a[0],&a[2]); break;
        }
    }
    for(int i=0;i<3;i++){
        if(a[i])
            cout << i+1;
    }
}

