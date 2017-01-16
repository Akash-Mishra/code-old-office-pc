#include <iostream>
using namespace std;
int main (){
	int num, dLeft;
	cin>>num>>dLeft;
	int array[num];
	for(int i = 0; i < num; i++){
		cin>>array[i];
	}
	int resultArray[num];
	for(int j = 0; j < num; j++){
		int temp = (j-dLeft)%num;
		if(temp < 0){
			resultArray[temp + num] = array[j];
		}
		else
			resultArray[temp] = array[j];
	}
	for(int i = 0; i < num; i++){
		cout<<resultArray[i]<<" ";
	}
}