#include <iostream>
using namespace std;
int sumDiff(int n){
	return ((n*(n+2)/4) - ((n*n)/4));
}
int main(){
	int n, sum=0;
	cin>>n;
	if (n%2==0)
	{
		sum = sumDiff(n);
	}
	else
		sum = sumDiff(n-1) - n;
	cout<<sum<<endl;
}