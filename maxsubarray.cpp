#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int max(int a,int b,int c)
{
	return max(max(a,b),c);
}

int max_crossing_sum(int arr[],int low,int mid,int high)
{
	int left_sum = INT_MIN;
	int sum =0;
	for(int i= mid;i>=low;i--)
	{
		sum+=arr[i];
		if(sum>left_sum)
			{
				left_sum =sum;
			}

	}
	sum =0;
	int right_sum = INT_MIN;
	for(int i=mid+1;i<=high;i++)
	{
		sum+=arr[i];
		if(sum>right_sum)
			right_sum= sum;
	}
	return max(left_sum,right_sum,left_sum+right_sum);
}
int Find_Max_Subarray(int arr[],int low,int high)
{
	int mid;
	if(low == high)  //base case : only one element
		return (arr[low]);

		mid = (low+high)>>1;
       
return max(Find_Max_Subarray(arr,low,mid),Find_Max_Subarray(arr,mid+1,high),max_crossing_sum(arr,low,mid,high));
	
}
int main()
{
	int n;
	cout<<"Enter size of array\n";
	cin>>n;
	int arr[10];
    cout<<"Enter elements in array\n";
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    int ans = Find_Max_Subarray(arr,0,n-1);
    cout<<"Max_Subarray is "<<ans;

	return 0;
}