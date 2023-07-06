#include<stdio.h>
#include<iostream>
using namespace std;
int count[5]={0,0,0,0,0};
// i v x l c

int main(){
    int n;
    int j,v,x,l,c;
    cin >> n;
    for(int i=1;i<=n;i++){
        int k=i;
        while(k>0){
            if(k>=100)      {count[4]+=1;   k-=100;}
            else if (k>=90) {count[4]+=1;   count[2]+=1;  k-=90;}
            else if (k>=50) {count[3]+=1;   k-=50;}
            else if (k>=40) {count[3]+=1;   count[2]+=1;  k-=40;}
            else if (k>=10) {count[2]+=1; k-=10;}
            else if (k>=9)  {count[2]+=1;   count[0]+=1;  k-=9;}
            else if (k>=5)  {count[1]+=1;   k-=5;}
            else if (k>=4)  {count[1]+=1;   count[0]+=1;  k-=4;}
            else if (k>=1)  {count[0]+=1;   k-=1;}
        }
    }
    for(int i=0;i<5;i++){
        cout << count[i] << " ";
    }
}

