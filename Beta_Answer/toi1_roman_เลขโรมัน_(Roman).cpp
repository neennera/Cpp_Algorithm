#include<bits/stdc++.h>
using namespace std;

long long int c[5]={0};

int roman(int m){
    int n=m;
    if(n<=0)
        return 0;
    else{
        if(n/100>=1){
            c[4]+=(n/100);
            n=n%100;
        }
        if(n>=50){
            if(n/10!=9){
                c[3]++;
                n-=50;
            }else{
                c[4]++;
                c[2]++;
                n-=90;
            }
        }
        if(n/10>=1){
            if(n/10==4){
                c[3]++;
                c[2]++;
            }else{
                c[2]+=n/10;
            }
            n=n%10;
        }
        if(n>=4){
            if(n==9){
                c[2]++;
                c[0]++;
                n-=9;
            }else if(n==4){
                c[1]++;
                c[0]++;
                n-=4;
            }
            else{
                c[1]++;
                n-=5;
            }

        }
        c[0]+=n;
        roman(m-1);
    }
}

int main(){
    int n,m;
    cin >> n;
    roman(n);
    for(int i=0;i<5;i++)
        cout << c[i] << " ";
}

