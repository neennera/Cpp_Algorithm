#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,h;
    cin >> w >> h;
    int win[w];
    for(int i=0;i<w;i++){
        win[i]=0;
    }
    int n;
    cin >> n;
    int five=0,ten=w;
    for(int k=0;k<n;k++){
        int a,x;
        cin >> x >> a;
        for(int i=0;i<a;i++){
            if(x+i>=w)
                break;
            win[x+i]+=1;
            if(win[x+i]==1){
                five++;
                ten--;
            }else if(win[x+i]==2){
                five--;
            }
        }
        //cout << ten << " " << five << endl;
    }
    //ten=0; five=0;
    /*for(int i=0;i<w;i++){
        if(win[i]==0)
            ten++;
        if(win[i]==1)
            five++;
    }*/
    cout << ten*h << " "<< five*h;
}

