// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        if (gcd(a, m) != 1) {
            return -1;
        }
        for (int i = m; i >= 0; --i) {
            if ((a * i) % m == 1)
                return i;
        }
        return -1;
    }
    int gcd(int a, int b) {
        if (b == 0) 
            return a;
        return gcd(b, a % b);
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends