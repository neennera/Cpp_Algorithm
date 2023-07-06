#include<bits/stdc++.h>
using namespace std;

long long int get(int n,int k){
    char num[n][10];
    for(int i=k;i<9;i+=3){
        string c;
        getline(cin,c);
        int h=0;
        for(int k=0;k<=4*n;k++){
            if((k+1)%4==0){
                h++;
                continue;
            }
            num[h][i+k-(4*h)]=c[k];
        }
    }

    int x=0;
    for(int h=0;h<n;h++){
        if(num[h][1]==' '){
            if(num[h][3]=='|')
                x+=4*pow(10,n-h-1); //4
            else
                x+=1*pow(10,n-h-1);   //1
        }else{
            if(num[h][3]==' '&&num[h][6]==' '){
                if(num[h][4]==' '){
                    x+=7*pow(10,n-h-1);  //7
                    continue;
                }
            }
            if(num[h][5]==' '){
                if(num[h][6]==' ')
                    x+=5*pow(10,n-h-1);  //5
                else
                    x+=6*pow(10,n-h-1);  //6
                continue;
            }
            if(num[h][4]==' '){
                x+=0*pow(10,n-h-1);   //0
                continue;
            }else{
            if(num[h][6]==' '){
                if(num[h][3]=='|'){
                    x+=9*pow(10,n-h-1);   //9
                    continue;
                }else{
                    x+=3*pow(10,n-h-1);   //3
                    continue;
                }
            }else{
                if(num[h][3]=='|'){
                    x+=8*pow(10,n-h-1);   //8
                    continue;
                }else{
                    x+=2*pow(10,n-h-1);   //2
                    continue;
                }
            }
            }

        }
    }
    //cout << "\n" <<x << endl;
    return x;

}

int main(){
    int n1,n2;
    cin >> n1 >> n2;
    long long int a=get(n1,-3);
    long long int b=get(n2,0);
    cout << a+b;
}


/*
for(int i=0;i<9;i+=3){
        for(int h=0;h<n;h++){
            for(int k=0;k<3;k++){
                cout << num[h][i+k];
            }
            cout << " ";
           }
        cout << "\n";
        }
*/

/*
if(num[h][3]=='|'&&num[h][6]==' '){
                if(num[h][6]==' ')
                    x+=5*pow(10,n-h-1);  //5
                else
                    x+=6*pow(10,n-h-1);  //6
                continue;
            }
*/

