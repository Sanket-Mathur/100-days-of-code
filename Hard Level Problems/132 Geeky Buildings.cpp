// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n) {
	    if (n < 3)
	        return false;
	        
	    int leftMin[n];
	    leftMin[0] = arr[0];
	    for (int i = 1; i < n; ++i) {
	        leftMin[i] = min(arr[i], leftMin[i-1]);
	    }
	       
	    stack<int> s;
	    for (int i = n-1; i >= 0; --i) {
	        if (s.empty()) {
	            s.push(arr[i]);
	        } else {
	            while (!s.empty() && leftMin[i] >= s.top()) {
	                s.pop();
	            }
	            
	            if (!s.empty() && leftMin[i] < arr[i] && arr[i] > s.top())
	                return true;
	            
	            s.push(arr[i]);
	        }
	    }
	    
	    return false;
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
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends