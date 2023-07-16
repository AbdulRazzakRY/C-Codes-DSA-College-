/* Dynamic Programming implementation
of Maximum Sum Increasing Subsequence
(MSIS) problem */
#include<stdio.h>

/* maxSumIS() returns the maximum sum of increasing subsequence in arr[] of size n */
int maxSumIS(int arr[], int n)
{
	int i, j, max = 0;
	int msis[n];
	for ( i = 0; i < n; i++ ) // Initialize msis value for all indexes
		msis[i] = arr[i];
	for ( i = 1; i < n; i++ ) // Compute maximum sum values in bottom up manner 
		for ( j = 0; j < i; j++ )
			if (arr[i] > arr[j] &&
				msis[i] < msis[j] + arr[i])
				msis[i] = msis[j] + arr[i];
	for ( i = 0; i < n; i++ ) // Pick maximum of all msis values 
		if ( max < msis[i] )
			max = msis[i];
	return max;    // returns maximum sum
}

// Driver Code
int main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Sum of maximum sum increasing "
			"subsequence is %d\n",
			maxSumIS( arr, n ) );
	return 0;
}
