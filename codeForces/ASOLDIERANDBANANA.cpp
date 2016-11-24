#include <iostream>
using namespace std;
int main(){
	long long int k,n,w;
	cin>>k>>n>>w;
	long long int result = (k*w*(w+1)/2) - n;
	if(result>0)
	    cout<<result<<endl;
    else
    	cout<<0<<endl;
	return 0;
}