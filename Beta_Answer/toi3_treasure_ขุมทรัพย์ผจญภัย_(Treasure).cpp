#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define SQ sqrt(2)/2
#define SS cos(45*PI/180)

int num(string c,int n){
    int m=0;
    //cout << n << "   ";
    for(int i=0;i<n;i++){
        m+=(c[i]-'0')*(pow(10,n-i-1));
    }
    return m;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    double x=0,y=0;
    string c;
    while(1){
            cin >> c;
            int n=c.length();
            if(c[0]=='*') break;
            switch(c[n-1]){
                case 'N': y+=num(c,n-1); break;
                case 'S': y-=num(c,n-1); break;
                case 'E':
                    switch(c[n-2]){
                        case 'N': x+=num(c,n-2)*SQ; y+=num(c,n-2)*SQ; break;
                        case 'S': x+=num(c,n-2)*SQ; y-=num(c,n-2)*SQ; break;
                        default: x+=num(c,n-1); break;
                    }
                    break;
                case 'W':
                    switch(c[n-2]){
                        case 'N': x-=num(c,n-2)*SQ; y+=num(c,n-2)*SQ; break;
                        case 'S': x-=num(c,n-2)*SQ; y-=num(c,n-2)*SQ; break;
                        default: x-=num(c,n-1); break;
                    }
                    break;            }

            //cout << " ---- "<< x << " " << y << endl;
    }
    printf("%.3f %.3f\n%.3f",x,y,sqrt(pow(x,2)+pow(y,2)));
}

