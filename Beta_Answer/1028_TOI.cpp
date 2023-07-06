#include<bits/stdc++.h>
using namespace std;
long double value[26]={0};
long double m[52]={0};
int k=0;
void process();
void print();
void cal(char s);
int main(){
    char op;
    do{
        cin >> op;
        if(op=='!')
            break;
        else{
            switch(op){
            case '=' : process(); break;
                case '#' : print(); break;
                case '+' :
                case '-' :
                case '*' :
                case '/' :
                    cal(op); break;
            }
        }
    }while(1);
    for(int i=0;i<k;i++){
        printf("%.0Lf\n",m[i]);
    }
    printf("!");
}

void cal(char s){
    char A,B;
    scanf(" %c",&A);
    scanf(" %c",&B);
    int a=A-'A';
    int b=B-'A';
    switch(s){
        case '+' : value[a]=value[a]+value[b]; break;
        case '-' : value[a]=value[a]-value[b]; break;
        case '*' : value[a]=1.0*value[a]*value[b]; break;
        case '/' : value[a]=floor(1.0*value[a]/value[b]); break;
    }
}

void process(){
    char c;
    int b;
    scanf(" %c",&c);
    scanf(" %d",&b);
    value[c-'A']=b;
}

void print(){
    char c;
    scanf(" %c",&c);
    m[k]=value[c-'A'];
    k++;
}

