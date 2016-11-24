#include <iostream>
#include <string>
using namespace std;
int main(){
	int counter = 0;
	string s;
	cin>>s;
	char temp;
	for (int i = 0; i < s.length(); i++)
	{
		/* code */
		temp = s[i];
		if((temp=='H') || (temp=='Q') || (temp=='9'))
			counter++;
	}
	if (counter)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}