// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k) {
        map<int, int> window;
        vector<int> result;
        int unique = 0;
        
        for (int i = 0; i < n; ++i) {
            auto find = window.find(arr[i]);

            if (find == window.end()) {
                unique++;
                window.insert(pair<int, int> (arr[i], i));
            } else {
                find->second = i;
            }
            
            if (i >= k - 1) {
                if (window.find(arr[i - k])->second == i - k) {
                    unique--;
                    window.erase(arr[i - k]);
                }
                result.push_back(unique);
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends