#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int maxv=INT_MIN;
    int ans=0,id=0,sum=0,k=0;

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++){
        sum=sum+a[i];
        k++;
        if(sum>maxv){
            maxv=sum;
            id=i;
            ans=k;
        }
        if(sum<=0){
            sum=0;
            k=0;
        }
    }

    if(maxv>=1){
        int j=id-ans+1;
        for(int i=0;i<ans;i++)
            cout << a[j+i] << " ";
        cout <<"\n"<< maxv;
    }
    else
        cout<<"Empty sequence";
}

