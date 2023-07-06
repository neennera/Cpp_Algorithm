#include<bits/stdc++.h>
using namespace std;
bool check=true;

int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    char a[m]={NULL},b[m]={NULL};
    scanf("%s",a);
    while(n-->1){
        scanf("%s",b);
        int h=0,j=0;
        while(j<m){
            if(h>2){
                break;
            }
            if(a[j]!=b[j])
                h++;
            j++;
        }
        if(h<=2&&check){
            strcpy(a,b);
        }else{
            check=false;
        }
    }
    printf("%s",a);
}

