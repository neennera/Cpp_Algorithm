#include<bits/stdc++.h>
using namespace std;

int c(int a[]){
    if(a[0]==a[1]-1&&a[1]==a[2]-1)
        return 0;
    if(a[0]==a[1]||a[1]==a[2]||a[0]==a[2])
        return 0;
    return 1;
}

int main(){
    int a[3],m=0;
    for(int i=0;i<3;i++)
        cin >> a[i];
    while(c(a)){
            m++;
        if(a[1]-a[0]>=a[2]-a[1]){
            a[2]=a[1]-1;
        }else{
            a[0]=a[1]+1;
        }
        sort(a,a+3);
    }
    cout << m;
}

