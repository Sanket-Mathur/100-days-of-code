// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        if (n == 1)
            return 0;
        long long int a = 0, b = 1, temp;
        for (long long int i = 1; i < n; ++i) {
            temp = (a + b) % 1000000007;
            a = b;
            b = temp;
        }
        return b;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends