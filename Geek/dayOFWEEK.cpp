#include <iostream>
using namespace std;
int dayofweek(int d, int m, int y){
	static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
	y-=m < 3;
	// cout<<(y-=m < 3)<<endl;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main(){
	int day = dayofweek(30, 8, 2010);
	cout<<day<<endl;

	return 0;
}