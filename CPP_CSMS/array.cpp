//find the number of greater number in the right side of an every index elements 

#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    //int arr[]={7,12,6,4,13,5};
    int arr[3][3]={4,9,2,3,10,11,6,13,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    

    vector<int> v;
    


    for(int i =0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            
            if(arr[i][j]<arr[i][j+1])
            {
                count++;
            }  
        }
        v.push_back(count);
    }

    for(int i =0 ;i<n;i++)
    {
        cout<<v[i];
    }

    return 0 ;
}