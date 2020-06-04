#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high)
{
    int x =arr[high];
    int i = low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }   
swap(arr[i+1],arr[high]);
return i+1;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int j= partition(arr,low,high);
        quicksort(arr,low,high-1);
        quicksort(arr,low+1,high);
    }
}
int main()
{
    int arr[10];
    int n;
    cout<<"Enter size\n";
    cin>>n;
    cout<<"Enter aray elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"Array elements after sorting are\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}