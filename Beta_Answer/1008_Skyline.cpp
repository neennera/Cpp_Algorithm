#include<bits/stdc++.h>
using namespace std;

int swapd(int *x,int *y){
    int m=*x;
    *x=*y;
    *y=m;
}

int main(){
    int n;
    cin >> n;
    int L,H,R;
    int B[256]={NULL};
    int k=0;
    for(int i=0;i<=256;i++)
        B[i]=0;
    for(int i=0;i<n;i++){
        cin >> L >> H >> R;
        if(R<L)
            swapd(&L,&R);
        if(k<R){
            k=R;
        }
        if(R==L){
            B[R]=H;
            continue;
        }
        int j=L-1;
        while(j<R-1){   //R -> R-1
            if(B[j]<H){
                B[j]=H;
            }
            j++;
        }
    }
    if(n==1){
        cout << k << " " << 0 << " ";
        //cout << k << " " << 0 << " ";
        return 0;
    }
    /*for(int i=0;i<k;i++){
        if(B[i+1]<B[i])
            B[i]=B[i+1];
    }*/
    for(int i=0;i<=k;i++){
        if(i==0&&B[i]==0)
            continue;
        if(B[i]==B[i-1]&&i!=0)
            continue;
        cout << i+1 << " " << B[i] << " ";
    }
}

