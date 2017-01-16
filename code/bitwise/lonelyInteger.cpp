#include <iostream>
#include <algorithm>
using namespace std;
int lonelyInteger(int arr[], int n){
	int result = 0, temp = arr[0];
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			temp = arr[i];
			arr[i] = arr[i]^arr[j];
			if(arr[i] == 0){
				result = temp; 
			}
		}
	}
	return result;
}
int main(){
	int size;
	cin>>size;
	int arrayLone[100];
	fill_n(arrayLone, size, -1);
	int num;
	for(int i = 0 ; i < size; i++){
		cin>>num;
		arrayLone[i] = num;
	}
	cout<<lonelyInteger(arrayLone, size)<<endl;
}