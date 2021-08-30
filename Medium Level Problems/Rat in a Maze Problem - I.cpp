// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        
        if (isSafe(m, n, 0, 0)) {
            checkPath(m, n, 0, 0, result, "");
        }
        
        sort(result.begin(), result.end());
        return result;
    }
    
    bool isSafe(vector<vector<int>> &m, int n, int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < n && m[i][j] == 1);
    }
    
    void checkPath(vector<vector<int>> &m, int n, int i, int j, vector<string> &result, string path) {
        if (i == n-1 && j == n-1) {
            result.push_back(path);
            return;
        }
        
        m[i][j] = 0;
        if (isSafe(m, n, i-1, j)) {
            checkPath(m, n, i-1, j, result, path+"U");
        }
        if (isSafe(m, n, i+1, j)) {
            checkPath(m, n, i+1, j, result, path+"D");
        }
        if (isSafe(m, n, i, j-1)) {
            checkPath(m, n, i, j-1, result, path+"L");
        }
        if (isSafe(m, n, i, j+1)) {
            checkPath(m, n, i, j+1, result, path+"R");
        }
        m[i][j] = 1;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends