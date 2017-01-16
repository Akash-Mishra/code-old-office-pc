#include <iostream>
using namespace std;
int binarySearch(int arra[], int x){
	int lo = 1;
	int high = 10;
	int mid = 0;
	while(lo <= high){
		mid = lo + (high-lo)/2;
		if (arra[mid] == x)
			return mid;
		else if (arra[mid] < x)
			lo = mid + 1;
		else
			high = mid - 1;
	}

	if(lo > high)
		return -1;
}
int main(){
	int i = 10;
	int array[10];
	for(int j = 0; j < i; j++)
		array[j] = j;
	// for(int j = 0; j < i; j++)
		// cout<<array[j]<<endl;
	cout<<binarySearch(array, 7)<<endl;
	return 0;
}