#include<bits/stdc++.h>
#include<math.h>
using namespace std;


int main() {
    int a[100][100];
    int n;
    int d1,d2;
    cin>>n;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cin>>a[x][y];
        }
    }
   
   d1=0;d2=0;
    for(int x=0;x<n;x++)
        {
        d1=d1+a[x][x];
    }
    for(int x=n-1;x>-1;x--)
        {
       
        d2=(d2+a[n-x-1][x]);   
    }
    int diff = d1-d2;
    if(diff<0){
        cout<<-(diff);
    }
    else
        cout<<diff;
    
    return 0;
}