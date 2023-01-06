#include<iostream>
using namespace std;

void merge(int *arr, int start , int end)
{
    int mid = (start + end )/ 2 ;

    int length1 = mid - start +1;
    int length2 = end - mid;

    int *arr1 = new int[length1];
    int *arr2 = new int[length2];

    int mainindex = start;


    for(int i = 0 ; i<length1 ;i++)
    {
        arr1[i]=arr[mainindex++];
    }
    
    mainindex = mid+1;
    for(int i = 0 ; i<length2 ;i++)
    {
        arr2[i]=arr[mainindex++];
    }

    int index1 = 0;
    int index2 = 0;

    mainindex = start;

    while(index1<length1 && index2<length2){
        if(arr1[index1]<arr2[index2]){
            arr[mainindex++]=arr1[index1++];}
        else    
            {arr[mainindex++]=arr2[index2++];}
    }
    
    while(index1<length1){
        arr[mainindex++]=arr1[index1++];}

    while(index2<length2){
        arr[mainindex++]=arr2[index2++];   }

    delete[] arr1;
    delete[] arr2;
         

}

void mergesort(int *arr, int start , int end )
{
    if(start>=end){
        return ;}


    int mid = (start + end )/ 2;

    mergesort(arr, start ,mid);

    mergesort(arr , mid+1 , end);   


    merge(arr,start , end) ;
}
int main() {

    int arr[] = {1 ,9 ,23,5,32,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    int start = 0;
    int end = size -1 ;

    mergesort(arr , start , end);

    for(int i = 0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}