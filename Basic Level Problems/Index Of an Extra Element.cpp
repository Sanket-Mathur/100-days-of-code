// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        int beg = 0, end = n - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (mid == n - 1) {
                return mid;
            } else if (a[mid] == b[mid]) {
                beg = mid + 1;
            } else {
                if (mid == 0) {
                    return 0;
                } else if (a[mid] == b[mid - 1]) {
                    end = mid - 1;
                } else {
                    return mid;
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}  // } Driver Code Ends