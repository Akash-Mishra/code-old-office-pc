#include <iostream>
using namespace std;
int main(){
	int n;
	int Anton = 0, Danik = 0;
	
	cin>>n;
	string a[n];
	cin>>a;
	for(int i=0; i < n; i++){
		// cin>>a;
		if (a[i] == 'A')
		{
			/* code */
			Anton++;
		}
		else 
			Danik++;
	}
	if(Anton<Danik)
		cout<<"Anton";
	else
		cout<<"Danik";
}