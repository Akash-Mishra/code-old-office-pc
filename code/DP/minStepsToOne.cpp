#include <iostream>
using namespace std;
int min(int a, int b){ return (a < b)?a:b; }
int minStepTo1(int n){
	int arr[n+1], i;
	arr[1] = 0;
	for(i = 2; i <= n; i++){
		arr[i] = 1 + arr[i-1];
		if(i % 2 == 0) arr[i] = min(arr[i], 1 + arr[i/2]);
		if(i % 3 == 0) arr[i] = min(arr[i], 1 + arr[i/3]);
	}
	return arr[n];
}
int main(){
	int n;
	cin>>n;
	cout<<minStepTo1(n);
	return 0;
}