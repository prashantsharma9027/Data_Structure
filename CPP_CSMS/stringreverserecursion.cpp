#include<iostream>
using namespace std;

void reverse(string &str , int i , int j)
{
    if(i>j)
        return;

    swap(str[i],str[j]);
    i++;
    j--;

    return reverse(str , i ,j) ;   
}

int main()
{
    string str ="prashant";
    
    int size = str.length();

    int i =0;
    int j=size-1;
    reverse(str,i,j);
    cout<<str;
    return 0;
}