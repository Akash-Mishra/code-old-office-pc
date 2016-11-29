#include <iostream>
using namespace std;
int fibo(int n){
	int result[n];
	result[0] = 1;
	result[1] = 1;
	for(int i = 2; i < n; i++)
		result[i] = result[i-1] + result[i-2];
	return result[n-1];
}
int main(){
	int num;
	cin>>num;
	cout<<"fibo: "<<num<<" = "<<fibo(num)<<endl;
}