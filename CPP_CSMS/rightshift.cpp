#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int temp=0;

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0 ;i<n ; i--)
    {
        arr[i+1]=arr[i];
        temp = arr[n-1];
        arr[1]=temp;
    }
    for(int j=0;j<n;j++){
        cout<<arr[j];
    }
    return 0;
}