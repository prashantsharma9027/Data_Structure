#include<iostream>
using namespace std;

int count( int n)
{
    if(n==0)
        return 1;
    
    cout<<n<<" ";
    return count(n-1);    
}

int factorial(int n)
{
    if(n==0)
        return 1;
    return n * factorial(n-1);    
}

int power(int n)
{
    if(n==0)
        return 1;

    return 2 * power(n-1);    
}

int fibo( int n)
{
    
}
int main()
{
    int n;
    cin>>n;

    // count(n);

    //cout<<factorial(n);

    cout<<power(n);

    return 0;
    

}