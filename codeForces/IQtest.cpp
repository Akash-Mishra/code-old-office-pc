#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i = n;
	int arr[n];
	int j = 0;
	while(i){
		cin>>arr[j];
		j++;
		i--;
	}
	int result = 1;
	if(arr[0]%2 == 0)
		for(int k = 0; k < n; k++){
			if(arr[k]%2 != 0)
				result = k + 1;
		}
	if(arr[0]%2 != 0)
		for(int p = 0; p < n; p++){
			if(arr[p]%2 == 0)
				result = p + 1;
		}

	cout<<result<<endl;

}