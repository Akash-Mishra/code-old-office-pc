#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n && !(n & (n-1)))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}