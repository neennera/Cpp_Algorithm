#include<bits/stdc++.h>
using namespace std;
double x=0,y=0;
int n=0,e=0,ne=0,nw=0;
int main(){
    char d[6]={NULL};
    while(d[0]!='*'){
        scanf("%s",d);
        int m=0;
        int i=0;
        while(d[i]>='0'&&d[i]<='9'){
            i++;
        }
        i--;
        for(int j=0;j<=i;j++){
            m+=(d[j]-'0')*pow(10,i-j);
        }
        i++;
        //cout << "\t" << m << endl;
        if(d[i+1]=='\0'){
            switch(d[i]){
                case 'N' : n+=m; break;
                case 'S' : n-=m; break;
                case 'E' : e+=m; break;
                case 'W' : e-=m; break;
            }
        }else{
            if(d[i]=='N'){
                if(d[i+1]=='E'){
                    ne+=m;
                }
                if(d[i+1]=='W'){
                    nw+=m;
                }
            }
            if(d[i]=='S'){
                if(d[i+1]=='E'){
                    nw-=m;
                }
                if(d[i+1]=='W'){
                    ne-=m;
                }
            }
        }
    }
    x=e+((ne-nw)/sqrt(2));
    y=n+((ne+nw)/sqrt(2));
    double k;
    k=sqrt(pow(x,2)+pow(y,2));
    printf("%.3f %.3f\n",x,y);
    printf("%.3f",k);
}

