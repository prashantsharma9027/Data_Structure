#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10];
    int n,i;
    int sum=0;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
   for(i=0;i<n;i++)
   {
    sum=sum+a[i];
   }
   cout<<sum;
   return 0;
}
