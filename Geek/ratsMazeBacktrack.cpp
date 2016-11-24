// c++ program to solve rat in a maze problem using backtracking
#include <iostream>
using namespace std;

// Maze size
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

// A utility function to print solution matrix sol[N][N];
void printSolution(int sol[N][N])
{
	for( int i =0 ; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			/* code */
			cout<<sol[i][j];
		}
		cout<<endl;
	}
}

// A utility function to check if x,y is valid index for N*N maze
bool isSafe(int maze[N][N], int x, int y){
	// if (x, y outside maze) return false
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;

	return false;
}


// This function solves the maze problem using bbacktracking. It mainly uses solveMazeUtil()
// to solve the problem. It returns false if no path is possible, otherwise returns true and prints
// the path in the form of 1s. Please note that there may be more than one solution, this function
// prints one of the feasible solution.

bool solveMaze(int maze[N][N]){
	int sol[N][N] = {{0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}};

    if(solveMazeUtil(maze,0,0,sol) == false){
    	cout<<"Solution doesn't exist"<<endl;
    	return false;
    }

    printSolution(sol);
    return true;
}

// A recursive utility function to solve the maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]){
	// if( x, y is goal) return true
	if(x == N-1 && y == N-1){
		sol[x][y] = 1;
		return true;
	}

	// check if maze[x][y] is valid
	if(isSafe(maze, x, y) == true){
		// mark x, y as part of solution path
		sol[x][y] = 1;

		// move forward in x direction
		if(solveMazeUtil(maze, x+1, y, sol) == true){
			return true;
		}

		// if moving in x direction does not give the solution then move down in y direction
		if (solveMazeUtil(maze, x, y+1, sol) == true)
		{
			/* code */
			return true;
		}

		// if none of the above movements work then Backtrack:
		// unmark x, y as part of solution path 
		sol[x][y] = 0;
		return false;

	}
	return false;
}

// driver function to test above function
int main(){
	int maze[N][N] = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
	solveMaze(maze);
	return 0;
}