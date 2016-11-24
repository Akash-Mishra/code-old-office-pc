// Given a cost matrix cost[][] and a position (m, n) in cost[][], 
// write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). 
// Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum
// of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally  
// lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. 
// You may assume that all costs are positive integers.

// dp implementation of MCP problem
#include <iostream>
using namespace std;
#define R 3
#define C 3

int min(int x, int y, int z){
	if (x < y)
		return (x < z)? x : z;
	else
		return (y < z)? y : z;
}

int minCost(int cost[R][C], int m, int n)
{
	int i, j;

	// instead of following line, we can use int tc[m+1][n+1] or dynamically
	// allocate memory to save space. The following line is used to keep the
	// program simple and make it working on all the compilers
	int tc[R][C];

	tc[0][0] = cost[0][0];

	// intialize first column of total cost array
	for (int i = 1; i <= m; i++)
	{
		tc[i][0] =  tc[i-1][0] + cost[i][0];
	}

	// initialize first row of total cost(tc) array
	for (int i = 1; i <= n; i++)
	{
		tc[0][i] = tc[0][i-1] + cost[0][i];
	}

	// construct rest of the tc array
	for(int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j];
		}

	return tc[m][n];
}

int main(){
	int cost[R][C] = { {1, 2, 3}, {4, 8, 2}, {1, 5, 3} };
	cout<<minCost(cost, 2, 2)<<endl;
	return 0;
}