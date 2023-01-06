#include<iostream>
using namespace std;

int partition(int arr[], int start , int end)
{
    int pivot = arr[start];

    int count = 0;

    for(int i = start +1; i<=end ; i++)
    {
        if(arr[i]<=pivot)
        count++;
    }

    int pivotindex = start + count;
    swap(arr[pivotindex],arr[start]);

    while(start<pivotindex && end>pivotindex){
        while(arr[start]<pivot) { start++; }
        while(arr[end]>pivot) { end--; }
        if(start<pivotindex && end>pivotindex)
            swap(arr[start++],arr[end--]);
    }

    return pivotindex;

}

void quicksort(int arr[],int start , int end)
{
    if(start>=end)
        return ;

    //partition

    int p = partition(arr,start, end);


    quicksort(arr,start,p-1);    
    quicksort(arr,p+1,end);    


}


int main()

{

     int arr[] = {1 ,9 ,23,5,32,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    int start = 0;
    int end = size -1 ;

    quicksort(arr , start , end);

    for(int i = 0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}