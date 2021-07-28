// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        set<int> result;
        unordered_set<int> zeros;
        
        for (int i = 0; i < n; ++i) {
            if (arr[abs(arr[i])] > 0) {
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            } else if (arr[abs(arr[i])] == 0) {
                if (zeros.find(abs(arr[i])) != zeros.end()) 
                    result.insert(abs(arr[i]));
                else
                    zeros.insert(abs(arr[i]));
            }else {
                result.insert(abs(arr[i]));
            }
        }
        
        vector<int> final;
        if(result.size() == 0) {
            final.push_back(-1);
        } else {
            for (auto i : result) 
                final.push_back(i);
        }
        
        return final;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends