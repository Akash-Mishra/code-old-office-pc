#include <iostream>
#include <limits.h>
using namespace std;

// returns minimum number of jumps to reach arr[h] from arr[l]
int minJumps(int arr[], int l, int h){
	// Base case: When source and destination are same
	if(h == l)
		return 0;

	// when nothing is reachable from the given source
	if( arr[l] == 0)
		return INT_MAX;

	// Traverse through all the points reachable from array[l]. Recursively get the minimum number of jumps
	// needed to reach array[h] from these reachable points
	int min = INT_MAX;
	for(int i = l + 1; i <= h && i <= 1 + arr[l]; i++){

		int jumps = minJumps(arr, i, h);
		if(jumps != INT_MAX && jumps + 1 < min)
			min = jumps + 1;
	}
	return min;
}

// driver function to test
int main(){
	int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<minJumps(arr, 0, n-1)<<endl;
	return 0;
}