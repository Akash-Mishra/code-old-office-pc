#include <iostream>
using namespace std;
int countTiles(int n){
	int array[n+1];
	// if(n < 3)
	// 	array[n] = n;
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	if(n > 2){
	    for(int i = 3 ; i <= n; i++)
		    array[i] = array[i-1] + array[i-2];
    }
	return array[n];
}
int main(){
	int num;
	cin>>num;
	cout<<countTiles(num)<<endl;
	return 0;
}