#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(pow(B,2)-(4*A*C)<0){
        cout << "No Solution";
        return 0;
    }
    if(C==0&&B==0){
        cout << sqrt(A) << " 0 "<< sqrt(A) <<" 0";
        return 0;
    }
    int x[100][3],c[1000][3],d=0,k=0;
    for(int i=1;i<=sqrt(A);i++){
        if(A%i==0){
            x[d][1]=i;
            x[d][2]=A/i;
            d++;
        }
    }
    for(int i=-10000;i<=10000;i++){
        if(i==0)
            continue;
        if(C%i==0){
            c[k][1]=i;
            c[k][2]=C/i;
            k++;
        }
    }
    for(int i=0;i<d;i++){
        for(int j=0;j<k;j++){
            if((x[i][1]*c[j][2])+((x[i][2]*c[j][1]))==B){
                printf("%d %d %d %d",x[i][1],c[j][1],x[i][2],c[j][2]);
                return 0;
            }
        }

    }
    cout << "No Solution";
}

/*
    if(pow(B,2)-(4*A*C)==0){
        cout << sqrt(A) << " "<< B/2/sqrt(A) << " "<< sqrt(A) << " "<< B/2/sqrt(A);
        return 0;
    }
*/

