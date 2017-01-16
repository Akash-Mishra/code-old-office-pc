// A naive recursive solution for Rod cutting problem
#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b){ return (a > b) ? a : b; }

// recursion ->  cutRod(n) = max(price[i], cutRoad(n-i-1)) for all i in {0,1,...,n-1}
int cutRod(int price[], int n){
	if(n <= 0)
		return 0;
	int max_val = INT_MIN;

	for(int i = 0; i < n; i++)
		max_val = max(max_val, price[i] + cutRod(price, n-i-1));

	return max_val;
}
int main(){
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<cutRod(arr, size)<<endl;
	return 0;
}