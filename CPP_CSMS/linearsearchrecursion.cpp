#include<iostream>
using namespace std;

bool linear(int arr[],int size,int element)
{
    if(size==0)
        return false;
    
    if(arr[0]==element)
        return true;

    return linear(arr+1,size-1,element);    
}
int main()
{
    int arr[] = { 1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element;
    cin>>element;

    cout<<linear(arr , size , element);
    return 0;
}