// C program for coin change problem by dynamic Programming. 
#include<stdio.h> 

int count( int S[], int m, int n ) 
{ 
	int i, j, x, y; 

	// We need n+1 rows as the table is constructed 
	// in bottom up manner using the base case 0 
	// value case (n = 0) 
	int table[n+1][m]; 
	
	// Fill the enteries for 0 value case (n = 0) 
	for (i=0; i<m; i++) 
		table[0][i] = 1; 

	// Fill rest of the table entries in bottom 
	// up manner 
	for (i = 1; i < n+1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// Count of solutions including S[j] 
			x = (i-S[j] >= 0)? table[i - S[j]][j]: 0; 

			// Count of solutions excluding S[j] 
			y = (j >= 1)? table[i][j-1]: 0; 

			// total count 
			table[i][j] = x + y; 
		} 
	} 
	return table[n][m-1]; 
} 

int main() 
{ 
	int m;
	printf("\nEnter size of array\n");
	scanf("%d",&m);
	int arr[m];
        printf("\nEnter coin denominations\n");
        for(int i =0;i<m;i++)
        scanf("%d",&arr[i]);  
	int n ;
	printf("\nEnter 'N' value \n");
	scanf("%d",&n); 
	printf("Total no of ways  %d ", count(arr, m, n)); 
	return 0; 
} 
//Execution Sunday 24 May 2020 10:14:09 PM IST 
