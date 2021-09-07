// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    {
        return solve(grid, 0, 0);
    }
    bool solve(int grid[N][N], int m, int n) {
        if (n == 9 && m == 8) {
            return true;
        } else if (n == 9) {
            m++;
            n = 0;
        }
        
        if (!grid[m][n]) {
            for (int i = 1; i < 10; ++i) {
                if (check(grid, m, n, i)) {
                    grid[m][n] = i;
                    
                    if (solve(grid, m, n + 1)) {
                        return true;
                    }
                    
                    grid[m][n] = 0;
                }
            }
        } else {
            if (solve(grid, m, n + 1)) {
                return true;
            }
        }
        
        return false;
    }
    bool check(int grid[N][N], int m, int n, int val) {
        for (int i = 0; i < 9; ++i) {
            if (grid[m][i] == val || grid[i][n] == val) {
                return false;
            }
        }
        for (int i = 3 * (m / 3); i < 3 * (m / 3) + 3; ++i) {
            for (int j = 3 * (n / 3); j < 3 * (n / 3) + 3; ++j) {
                if (grid[i][j] == val) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << grid[i][j] << " ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends