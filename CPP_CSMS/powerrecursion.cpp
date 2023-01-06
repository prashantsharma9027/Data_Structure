#include<bits/stdc++.h>
using namespace std;

int pow(int a , int b)
{
    if(b==0)
        return 1;

    int ans = pow(a, b/2);

    if(b%2==0)
        return ans*ans;
    else
        return a * ans *ans;        
}

int main()
{
    int a, b;
    cin>>a>>b;


    cout<<pow(a,b);

    return 0;
}