#include<bits/stdc++.h>
using namespace std;
int score[4][4]={0};
char name[4][21];
int point[4];

int sumA(int n){
    int s=0;
    for(int i=0;i<4;i++){
        if(n!=i)
            s=s+score[n][i]-score[i][n];
    }
    return s;
}

int sumB(int n){
    int s=0;
    for(int i=0;i<4;i++){
        if(n!=i)
            s=s+score[n][i];
    }
    return s;
}

int equa(int a,int b,int *id){
    if(sumA(a)>sumA(b)){
            cout << name[a] << " " << point[a]<< endl;
            point[a]=-10;
        }else if(sumA(a)<sumA(b)){
            cout << name[b] << " " << point[b]<< endl;
            *id=a;
        }else{
            if(sumB(a)>sumB(b)){
                cout << name[a] << " " << point[a]<< endl;
                point[a]=-10;
            }else{
                cout << name[b] << " " << point[b]<< endl;
                *id=a;
            }
        }
}

int main(){
    for(int i=0;i<4;i++)
        cin >> name[i];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> score[i][j];
        }
    }
    //x=do a score y=lose a score
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(score[i][j]>score[j][i])
                point[i]+=3;
            if(score[i][j]==score[j][i]&&i!=j)
                point[i]+=1;
        }
    }
    bool check;
    int id=0;
    for(int i=0;i<4;i++){
        id=0;
        for(int j=0;j<4;j++){
            if(point[j]>point[id]){
                id=j;
            }
        }
        for(int j=0;j<4;j++){
            if((point[j]==point[id]&&id!=j)&&(point[j]>=0)){
                equa(j,id,&id);
            }
        }
        if(point[id]>=0){
            cout << name[id] << " " << point[id]<< endl;
            point[id]=-10;
        }
    }
}

