// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        if (!A.length() && !B.length() && !C.length()) 
            return true;
        else if (!C.length())
            return false;
        
        bool x = A.length() && C[0] == A[0] && isInterleave(A.substr(1), B, C.substr(1));
        bool y = B.length() && C[0] == B[0] && isInterleave(A, B.substr(1), C.substr(1));
        
        return x || y;
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends