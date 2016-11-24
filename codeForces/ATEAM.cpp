#include <iostream>
using namespace std;
int main(){
	int num;
	cin>>num;
	int num1, num2, num3, counter=0;
	// int probArray[num][3];
	for (int j = 0; j < num; j++)
	{
		/* code */
		// for (int i = 0; i < 3; i++)
	      // {
		     /* code */
	      	cin>>num1>>num2>>num3;
	      	if (num1+num2+num3>=2)
	      	{
	      		counter++;
	      	}
	      	num1=0;
	      	num2=0;
	      	num3=0;
	      // }
	}
	cout<<counter<<endl;
	
}