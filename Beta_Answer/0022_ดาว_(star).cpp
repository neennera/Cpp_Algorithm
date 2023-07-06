#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int wid=n-(n+1)%2;
    int mid=n/2+n%2;
    for(int i=0;i<n;i++){
        for(int j=0;j<wid;j++){
            if(i<mid){
                if(j==(wid/2)-i||j==wid/2+i)
                    cout << "*";
                else
                    cout << "-";
            }
            else{
                if(j==(wid-1-(i-mid)-(n%2))||j==(i-mid)+1-((n+1)%2))
                    cout << "*";
                else
                    cout << "-";
            }
        }
        cout << endl;
    }
}

