// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        int N = grid.size(), M = grid[0].size();
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == '1') {
                    unmark(grid, N, M, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    void unmark(vector<vector<char>> &grid, int N, int M, int i, int j) {
        if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        unmark(grid, N, M, i-1, j-1);
        unmark(grid, N, M, i-1, j);
        unmark(grid, N, M, i-1, j+1);
        unmark(grid, N, M, i, j-1);
        unmark(grid, N, M, i, j+1);
        unmark(grid, N, M, i+1, j-1);
        unmark(grid, N, M, i+1, j);
        unmark(grid, N, M, i+1, j+1);
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends