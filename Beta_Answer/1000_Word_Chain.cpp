#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char a[n]={NULL},b[n]={NULL};
    scanf("%s",a);
    bool check=false;
    m--;
    while(m--){
        scanf("%s",b);
        int h=0;
        if(check)
            continue;
        for(int i=0;i<n;i++){
            if(h>2)
                break;
            if(a[i]!=b[i])
                h++;
        }
        if(h<=2){
            strcpy(a,b);
        }else
            check=true;
    }
    printf("%s",a);
}

