// f(n) = f(n-1)*f(n-1) + f(n-2);
#include <iostream>
using namespace std;
long long int fiboModified(long long int t1, long long int t2, long long int n){
	long long int resultArray[n];
	for (int i = 0; i < n; i++)
	{
		/* code */
		resultArray[n] = -1;
	}
	// if (resultArray[n]!=-1)
	// {
	// 	 // code 
	// 	return resultArray[n];
	// }
	resultArray[0] = t1;
	resultArray[1] = t2;
	// if (n == 1)
	// {
	// 	/* code */
	// 	resultArray[0] = t1;
	// }
	// else if(n == 2){
	// 	resultArray[1] = t2;
	// } if (n == 1)
	// {
	// 	/* code */
	// 	resultArray[0] = t1;
	// }
	// else if(n == 2){
	// 	resultArray[1] = t2;
	// }  
	for (int i = 2; i < n; i++)
	{
		/* code */
		resultArray[i] = resultArray[i-1]*resultArray[i-1] + resultArray[i-2];
	}
	return resultArray[n-1];
}
int main(){
	long long int i,j,up;
	cin>>i>>j>>up;
	cout<<fiboModified(i,j,up)<<endl;
	return 0;
}