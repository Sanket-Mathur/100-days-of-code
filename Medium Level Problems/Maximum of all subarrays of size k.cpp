// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> window;
        for (int i = 0; i < k; ++i) {
            while (!window.empty() && arr[i] >= arr[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        
        vector<int> result;
        
        for (int i = k; i < n; ++i) {
            result.push_back(arr[window.front()]);
            while (!window.empty() && i - k >= window.front()) {
                window.pop_front();
            }
            while (!window.empty() && arr[i] >= arr[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        result.push_back(arr[window.front()]);
        
        return result;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends