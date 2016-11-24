// A dp approach to find the minimum number of coins that make a value
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
// #define INT_MAX 99999999

// m is the size of coin array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum value of coins
	// required for i value so table[V] will have the result
	int table[V+1];

	// Base case( that is if given value V is 0)
	table[0] = 0;

	// initialize all table values as infinite
	for (int i = 1; i <= V; i++)
	{
		/* code */
		table[i] = 999999;
	}

	// Compute minimum coins required for all values from 1 to V
	for (int i = 1; i <= V; i++)
	{
		/* code */
		for (int j = 0; j < m; j++)
		{
			/* code */
			if (coins[j] <= i)
			{
				/* code */
				int sub_res = table[i-coins[j]];
				if (sub_res != 999999 && sub_res + 1 < table[i])
				{
					/* code */
					table[i] = sub_res + 1;
				}
			}
		}
	}
	return table[V];
}

// Driver program to test above function
int main(){
	int coins[] = {9, 6, 5, 1};
	int m = 4; // sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout<<"Minimum coins required is "<<minCoins(coins, m, V);
	return 0;
}