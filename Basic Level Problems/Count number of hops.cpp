// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        long long a = 1, b = 2, c = 4, temp;
        if (n <= 3) {
            if (n == 1) return 1;
            else if (n == 2) return 2;
            return 4;
        }
        for (int i = 0; i < n - 3; ++i) {
            temp = (a + b + c) % 1000000007;
            a = b;
            b = c;
            c = temp;
        }
        return c % 1000000007;
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends