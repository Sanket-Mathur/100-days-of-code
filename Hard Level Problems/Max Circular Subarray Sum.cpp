// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        int res = arr[0], kmin = arr[0], kmax = arr[0], s1 = arr[0], s2 = arr[0];
        
        for (int i = 1; i < n; ++i) {
            s1 = max(arr[i], s1 + arr[i]);
            kmax = max(kmax, s1);
            res += arr[i];
        }
        
        for (int i = 1; i < n; ++i) {
            s2 = min(arr[i], s2 + arr[i]);
            kmin = min(kmin, s2);
        }
        
        if (kmax < 0)
            return kmax;
        
        return max(kmax, res - kmin);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends