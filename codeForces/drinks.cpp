#include <iostream>
using namespace std;
int main(){
	int num, sum =0, num1;
	cin>>num;
	int x = num;
	while(x>0){
		cin>>num1;
		sum += num1;
		x--;
	}
	float result = sum /(num * 100);
	cout<<result<<endl;
}