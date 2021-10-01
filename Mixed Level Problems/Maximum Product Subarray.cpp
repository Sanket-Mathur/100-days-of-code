// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long maxM = 1, minM = 1;
	    long long result = arr[0];
	    
	    for (long long i : arr) {
	        if (i < 0) {
	            swap(minM, maxM);
	        }
	        
	        minM = min(i, minM * i);
	        maxM = max(i, maxM * i);
	        
	        result = max(result, maxM);
	    }
	    
	    return result;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends