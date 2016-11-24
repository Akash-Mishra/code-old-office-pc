#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num1 = 0, num2 = 0, num3 = 0, sumx = 0, sumy = 0, sumz = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>num1>>num2>>num3;
		sumx += num1;
		sumy += num2;
		sumz += num3;
		num1=0;
		num2=0;
		num3=0;
	}
	if (sumx==0 && sumy == 0 && sumz == 0)
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;

	return 0;
}