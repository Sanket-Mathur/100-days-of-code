// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        
        if (sum % k)
            return false;
        vector<bool> visited(n, false);
        return check(a, n, k, visited, sum/k, 0, 0);
    }
    
    bool check(int a[], int n, int k, vector<bool> &visited, int sum, int beg, int curr) {
        if (k == 1)
            return true;
        if (curr == sum)
            return check(a, n, k-1, visited, sum, 0, 0);
        
        for (int i = beg; i < n; ++i) {
            if (!visited[i] && curr + a[i] <= sum) {
                visited[i] = true;
                if (check(a, n, k, visited, sum, i + 1, curr + a[i])) {
                    return true;
                }
                visited[i] = false;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends