// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> hash;
        int cnt = 0;
        
        for (int i = n-1; i >= 0; --i) {
            if (hash.find(k - arr[i]) != hash.end()) {
                cnt += hash[k - arr[i]];
            }
            
            if (hash.find(arr[i]) == hash.end()) {
                hash[arr[i]] = 0;
            }
            hash[arr[i]] += 1;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends