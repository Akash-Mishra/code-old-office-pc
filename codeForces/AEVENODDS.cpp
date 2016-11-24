#include <iostream>
using namespace std;
int main(){
	long long int num,key;
	cin>>num>>key;
	if(key<=num/2){
		long long int temp = 2*key-1;
		cout<<temp<<endl;
	}
	else{
		long long int hola = num/2 + 2 * (key-num/2);
		cout<<hola<<endl; 
	}
}