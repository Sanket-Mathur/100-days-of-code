// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int res = 0, value;
        bool neg = false;
        for (auto c : str) {
            if (c == '-') {
                neg = true;
                continue;
            }
            
            value = c - '0';
            if (value < 0 || value > 9) {
                return -1;
            }
            res = (res * 10) + value;
        }
        
        return neg ? -res : res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends