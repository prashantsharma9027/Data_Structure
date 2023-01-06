#include<iostream>
using namespace std;

bool sorted(int arr[], int size)
{
    if(size==0 || size ==1)
        return true;

    if(arr[0]>arr[1])
        return false; 

    return sorted((arr+1), size-1);       
}

int sum(int arr[],int size)
{
    if(size==0)
        return 0;
    if(size==1)
        return arr[0];

    return (arr[0]+ sum(arr+1,size-1));        
}

bool binarysearch(int arr[], int size , int start , int end , int element)
{
    if(start>end)
        return false;
    
    int mid = start + (end -start)/2;

    if(arr[mid]==element)
        return true;

    if(arr[mid]>element)
        return binarysearch(arr, size/2 , start  , mid-1, element);
    else
        return binarysearch(arr , size/2 , mid+1 , end , element);        
}
int main()
{
    int arr[]= {1,2,3,4,5,6};

    int size = sizeof(arr)/sizeof(arr[0]);

    int start = 0;
    int end = size -1;

    int element;
    cin>>element;


    cout<<binarysearch(arr,size,start,end,element);
    

    // cout<<sum(arr , size);
    return 0;
}