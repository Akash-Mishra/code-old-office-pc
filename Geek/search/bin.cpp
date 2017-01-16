#include <iostream>
using namespace std;


// A recursive binary search function. It returns location of x in given array arr[1..r] is present, otherwise -1
int binarySearch(int array[], int l, int r, int x){
	// int lo, hi;
	// lo = 0;
	// hi = n-1;
	
	while(r >= l){
		int mid = l + (r - l)/2;

		// if the element is present at the middle itself
		if(array[mid] == x)
			return mid;

		// if the element is smaller than the mid, it can only be present in left subarray
		else if(array[mid] > x)
			return binarySearch(array, l, mid-1, x);

		// else element can only be present in right subarray
		else
			return binarySearch(array, mid+1, r, x);
	}
	return -1;
}
int main(){
	int array[] = {1 , 2, 3, 4, 5, 6};
	int x = 2;
	int size = sizeof(array)/sizeof(array[0]);
	cout<<binarySearch(array, 0, size-1, x)<<endl;
	return 0;
}