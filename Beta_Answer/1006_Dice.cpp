#include<bits/stdc++.h>
using namespace std;

int roll(map <char,int> &dice,char a,char b,char c,char d){
    int thm=dice[d];
    dice[d]=dice[c];
    dice[c]=dice[b];
    dice[b]=dice[a];
    dice[a]=thm;
}

int main(){
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        map <char,int> dice{{'A',1},{'F',2},{'L',3},{'B',5},{'R',4},{'U',6}};
        //above1 front2 left3 back4 right5 under6
        cin >> s;
        for(auto c:s){
            switch(c){
                case 'F' : roll(dice,'A','F','U','B'); break;
                case 'B' : roll(dice,'A','B','U','F'); break;
                case 'L' : roll(dice,'A','L','U','R'); break;
                case 'R' : roll(dice,'A','R','U','L'); break;
                case 'C' : roll(dice,'F','L','B','R'); break;
                case 'D' : roll(dice,'F','R','B','L'); break;
            }
        }
        printf("%d ",dice['F']);
    }
}

