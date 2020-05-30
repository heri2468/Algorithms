#include<iostream>
#include<time.h>
#define e 2.71828
using namespace std;
//to find  closest integer of num
int roundNo(float num)
{
	return num<0?num - 0.5 : num +0.5;
}
//finds best candidate using n/e rule.
//candidate [] represents talents of n candidates.
void printBestCandidate(int candidate[],int n)
{
	//calculating sample size for benchmarking
	int sample_size = roundNo(n/e);
	cout<<"\nSample size is "<<sample_size<<endl;
	//finding best candidate in sample size
	int best = 0;
	for(int i=1;i<sample_size;i++)
		if(candidate[i]>candidate[best])
			best = i;
	//finding the first best candidate that is better than benchamark size
    for(int i=sample_size;i<n;i++)
    	if(candidate[i]>=candidate[best])
    	{
    		best =i;
    		break;
    	}
    
	if(best>=sample_size)
		cout<<"Best candidate found is\t"<<best+1<<" with talent\t"<<candidate[best]<<endl;
	else
		cout<<"Couldn't find a best candidate";
}

int main()
{
	int n; //candidates
	cout<<"Enter how many candidates?\n";
	cin>>n;
	int candidate[n];
	srand(time(0));
	for(int i=0;i<n;i++)
		candidate[i] = 1+rand()%8;
	cout<<"candidate : ";
	for(int i=0;i<n;i++)
		cout<<i+1<< " ";
	cout<<endl;
	cout<<"talents :";
	for(int i=0;i<n;i++)
		cout<<candidate[i]<<" ";
	printBestCandidate(candidate,n);
    
	return 0;
}