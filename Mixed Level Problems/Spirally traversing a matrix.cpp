// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left = 0, right = c - 1, top = 0, bottom = r - 1;
        vector<int> result;
        
        while (result.size() < r * c) {
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            if (top != bottom) {
                for (int i = right - 1; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
            }
            if (left != right) {
                for (int i = bottom - 1; i >= top + 1; --i) {
                    result.push_back(matrix[i][left]);
                }
            }
            
            ++left; --right;
            ++top; --bottom;
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends