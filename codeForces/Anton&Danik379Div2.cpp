#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	char s[n];
	int Anton = 0, Danik = 0;
	for(int i = 0; i < n; i++){
	cin>>s[i];
	if(s[i] == 'A')
			Anton++;
	else
			Danik++;
}
	// int Anton = 0, Danik = 0;
	// for(int i = 0; i < n; i++){
	// 	if(s[i] == 'A')
	// 		Anton++;
	// 	else
	// 		Danik++;
	// }
	if(Anton > Danik)
		cout<<"Anton"<<endl;
	else if(Anton < Danik)
		cout<<"Danik"<<endl;
	else
		cout<<"Friendship"<<endl;
}