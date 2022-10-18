#include<bits/stdc++.h>
#include "rescuelib.h"

using namespace std;
#define ll long long
#define ft first
#define sd second
#define MAX 200005

int R,C;
int lx,rx,ly,ry;

int wall_x(){
    ly=C;
    ly = C-(min(l,r)-find_x());
}

int wall_y(int k){
    if(1){

    }
}

int find_x(){
    int l= drop_robot(lx,ly), r= drop_robot(rx,ly);
    if(l==-1 && r==-1){
        wall_x();
        return 0;
    }
    if(l==-1 || r==-1){
        wall_y((int)(l==-1));
        return 0;
    }
    int c=((R)-abs(l-r))>>1;
    if(l==r){
        lx = rx = 1+c;
    }else if(l>r){
        lx = rx = rx-c; 
    }else{
        lx = rx = lx+c;
    }
    return c;
}

int find_y(){
    int l= drop_robot(lx,ly), r= drop_robot(lx,ry);
    int c=((C)-abs(l-r))>>1;
    if(l==r){
        ly = ry = 1+c;
    }else if(l>r){
        ly = ry = ry-c; 
    }else{
        ly = ry = ly+c;
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    get_size(R,C);
    lx=1, rx=R, ly=1,ry=C;
    
    find_x();
    find_y();

    answer(lx,ly);
    return 0;
}