// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int sum = 0;
        int first = 0, last = 0;
        while (sum != s) {
            if (sum < s) {
                if (last == n)
                    break;
                sum += arr[last++];
            } else {
                if (first == n)
                    break;
                sum -= arr[first++];
            }
        }
        
        vector<int> result;
        if (sum == s) {
            result.push_back(first+1);
            result.push_back(last);
        } else {
            result.push_back(-1);
        }
        return result;
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
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends