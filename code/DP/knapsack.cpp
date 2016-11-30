#include <iostream>
#include <algorithm>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
// function has value array and weight array along with the size of array and Max weight as input
// output is the max value that can be obtained 
void knapsack(int val[], int size, int wt[], int W){
	int dp[size];
	fill_n(dp, size, -100);
	dp[0] = 0;
	for(int p = 1; p < size; p++){
		for (int w = W; w > 0; w++)
		{
			/* code */
			if (w >= wt[p])
			{
				/* code */
				dp[w] = max(dp[w], dp[w-wt[p]] + val[p]);
			}
		}
	}
	for(int i = 0; i < size; i++)
		cout<<dp[i]<<"  ";
}

// main function
int main() {
	int value[10];
	int weight[10];
	int sizeOfArray = 0;
	int num;
	int maxWeight;
	cin>>sizeOfArray;
	fill_n(value, sizeOfArray, -10);
	fill_n(weight, sizeOfArray, -10);

	int test = sizeOfArray;
	int i = 0;
	while(i < sizeOfArray){
		cin>>value[i]; // = num;
		i++;
	}

	i = 0;
	while( i < sizeOfArray){
		cin>>weight[i];
		i++;
	}
	cin>>maxWeight;

	knapsack(value, sizeOfArray, weight, maxWeight);
	// cout<<result<<endl;

	return 0;
}
