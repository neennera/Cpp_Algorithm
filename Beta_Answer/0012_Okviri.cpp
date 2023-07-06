#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int main(){
    int k,m=0,h=0;
    char a[16],d[4]="*##";
    cin >> a;
    int n=strlen(a);
    for(int i=0;i<5;i++){
        m=0;
        while(m<n){
            if((m+1)%3==0) k=0;
            else if(m==0||((n%3==1)&&m==n-1)){
                k=0;
            }else
                k=1;

            if(m%3==1&&m!=n-1){
                if(!(n%3==0))
                    h=0;
                h=1;
            }else
                h=0;
            if(n==2&&m==1){
                k=1;
                h=0;
            }
            if((m%3==0&&m==n-1)&&m!=0){
                k=1;
                h=0;
            }

            for(int j=k;j<5-h;j++){
                if(i==2&&j==(5-k)/2)
                    cout << a[m];
                else if(i<2&&(j==((5-k)/2)+i||j==((5-k)/2)-i))
                    cout << d[(m+1)%3];
                else if(i>=2&&(j==i-2||j==(5-i+1)))
                    cout << d[(m+1)%3];
                else
                    cout << ".";
            }
            m++;
            h=0;
        }
        cout << "\n";
    }
}

