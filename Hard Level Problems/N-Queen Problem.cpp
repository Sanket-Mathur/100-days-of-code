// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        solve(board, n, 0, result);
        return result;
    }
    
    void solve(vector<vector<int>> &board, int n, int row, vector<vector<int>> &result) {
        if (row == n) {
            vector<int> path;
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == 1) {
                        path.push_back(j + 1);
                    }
                }
            }
            
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (isPossible(board, n, row, i)) {
                board[row][i] = 1;
                solve(board, n, row + 1, result);
                board[row][i] = 0;
            }
        }
    }
    
    bool isPossible(vector<vector<int>> &board, int n, int row, int col) {
        for (int i = 0; i < n; ++i) {
            if (board[row][i] || board[i][col])
                return false;
        }
        
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j])
                return false;
        }
        for (int i = row, j = col; i < n && j < n; ++i, ++j) {
            if (board[i][j])
                return false;
        }
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j])
                return false;
        }
        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (board[i][j])
                return false;
        }
        
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends