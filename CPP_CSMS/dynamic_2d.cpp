#include<iostream>
using namespace std;
int main()
{
    int row, column;
    cout<<"enter the value of row";
    cin>>row;
    cout<<"enter the value of column";
    cin>>column;

//creation of 2d array 
    int **arr = new int*[row];
    for(int i =0;i<row;i++)
    {
        arr[i]=new int[column];
    }
    

//insetion into 2d array
    for(int i =0;i<row;i++)
    {
        for(int j=0;j<row;j++)
        {
            cin>>arr[i][j];
        }
    }

//display of 2d array
    for(int i =0;i<row;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }   

//releasing memory 
    for(int i =0;i<row;i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}