#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// DP implementation of LIS
using namespace std;

// lis() returns the length of the longest increasing subsequence in arr[] of size n
int lis(int arr[], int n){
	int *lis, i, j, max=0;
	lis = (int*)malloc(sizeof(int ) *n);

	// initialize LIS value for all indexes
	for(i = 0; i < n; i++){
		lis[i] = 1;
	}

	//compute optimised LIS values in bottom up manner
	for(i = 0;i < n; i++){
		for(j = 0; j < i; j++){
			if(arr[i] > arr [j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}

	// Pick maximum of all LIS values
	for( i = 0; i < n; i++)
		if( max < lis[i])
			max = lis[i];


    // free memory to avoid memory leak
	free(lis);

	return max;
}
// driver function
int main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<lis(arr, n)<<endl;
	return 0;
}
