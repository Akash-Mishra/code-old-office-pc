#include <iostream>
using namespace std;

int noOfOnes(int n){
	int count = 0;
	while(n){
		 n = n & (n-1);
		 cout<<n<<endl;
		 count++;
	}
	return count;
}

// Driver function
int main(){
	int input;
	cin>>input;
	cout<<"---------------------------------------\n"<<noOfOnes(input)<<endl;
	return 0;
}