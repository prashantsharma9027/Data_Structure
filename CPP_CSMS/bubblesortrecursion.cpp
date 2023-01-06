#include<iostream>
using namespace std;

void bubblesort(int arr[] , int size)
{
    if(size==0 || size ==1)
        return ;

    for(int i =0 ;i<size-i; i++)
    {
        if(arr[i]>arr[i+1]) 
            swap(arr[i],arr[i+1]);
    }

    bubblesort(arr ,size-1);

}

int main()
{
    int arr[] ={ 2,7,3,4,8};
    int size = sizeof(arr)/sizeof(arr[0]);


    bubblesort(arr, size);

    for(int i = 0 ; i<size;i++)
    {
        cout<<arr[i];
    }   
    return 0;



}