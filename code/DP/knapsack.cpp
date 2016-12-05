
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int knap(int val[], int size, int Sum){
	int minRes[100];
	fill_n(minRes, 100, INT_MIN);
	minRes[0] = 0;

	for(int i = 1; i < Sum; i++){
		for(int j = 0; j < size; j++){
			if (val[j] <= i && (minRes[i - val[j]] + 1 < minRes[i]))
			{
				/* code */
				minRes[i] = minRes[i - val[j]] + 1;
			}
		}
	}
	
	return minRes[Sum];
}

// for(int i = 0; i < 100; i++){
// 		cout<<minRes[i]<<endl;
// 	}

int main(){
	int val[] = {1, 3, 5};
	int size = 3;
	int sum = 100;
	cout<<knap(val, size, sum);
}