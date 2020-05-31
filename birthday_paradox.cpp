#include<stdio.h> 
int main(){ 

	// Assuming non-leap year 
	float num = 365; 

	float denom = 365; 
	float pr; 
	int n = 0; 
	printf("Probability to find : "); 
	scanf("%f", &pr); 

	float p = 1; 
	while (p > pr){ 
		p *= (num/denom); 
		num--; 
		n++; 
	} 

	printf("\nTotal no. of people out of which there "
		" is %0.1f probability that two of them "
		"have same birthdays is %d ", p, n); 

	return 0; 
} 
