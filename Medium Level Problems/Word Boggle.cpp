// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string> result;
	    
	    int N = board.size(), M = board[0].size();
	    
	    for (auto i : dictionary) {
	        if (checkString(board, i, N, M))
	            result.push_back(i);
	    }
	    
	    return result;
	}
	
	bool checkString(vector<vector<char>>& board, string key, int N, int M) {
	    for (int i = 0; i < N; ++i) {
	        for (int j = 0; j < M; ++j) {
	            if (board[i][j] == key[0] && traverse(board, key, 0, i, j, N, M)) {
	                return true;
	            }
	        }
	    }
	    return false;
	}
	
	bool traverse(vector<vector<char>>& board, string key, int k, int i, int j, int N, int M) {
	    if (key.length() == k) {
	        return true;
	    } else if (i < 0 || i >= N || j < 0 || j >= M || board[i][j] != key[k]) {
	        return false;
	    }
	    
	    char temp = board[i][j];
	    board[i][j] = ' ';
	    
	    if (traverse(board, key, k+1, i-1, j-1, N, M) ||
    	    traverse(board, key, k+1, i-1, j, N, M) ||
    	    traverse(board, key, k+1, i-1, j+1, N, M) ||
    	    traverse(board, key, k+1, i, j-1, N, M) ||
    	    traverse(board, key, k+1, i, j+1, N, M) ||
    	    traverse(board, key, k+1, i+1, j-1, N, M) ||
    	    traverse(board, key, k+1, i+1, j, N, M) ||
    	    traverse(board, key, k+1, i+1, j+1, N, M)
	    ) {
	        board[i][j] = temp;
	        return true;
	    }
	    
	    board[i][j] = temp;
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends