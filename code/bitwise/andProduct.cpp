#include <iostream>
using namespace std;
long bitwiseAnd(long a, long b){
	long result = a;
	for(long i = a; i <= b; i++){
		result = result & i;
	}
	return result;
}
int main(){
	int testCases;
	cin>>testCases;
	while(testCases){
		long a, b;
		cin>>a>>b;
		cout<<bitwiseAnd(a, b)<<endl;
		testCases--;
	}
	return 0;
}