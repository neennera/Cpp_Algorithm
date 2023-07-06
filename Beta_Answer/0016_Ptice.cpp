#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char A[4]="ABC",B[5]="BABC",G[7]="CCAABB";
    char name[4][10]={"Adrian","Bruno","Goran"};
    int score[3]={0,0,0};
    int n,i=0;
    cin >> n;
    char ans;
    for(int i=0;i<n;i++){
        cin >> ans;
        if(ans==A[i%3])
            score[0]++;
        if(ans==B[i%4])
            score[1]++;
        if(ans==G[i%6])
            score[2]++;
    }
    int maxv=score[0];
    for(int i=0;i<3;i++){
        if(score[i]>maxv)
            maxv=score[i];
    }
    cout << maxv << endl;
    for(int i=0;i<3;i++){
        if(score[i]==maxv)
            cout <<name[i]<<endl;
    }
}

