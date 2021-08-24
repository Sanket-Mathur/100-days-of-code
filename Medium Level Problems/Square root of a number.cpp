// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
    if (x == 0 || x == 1)
        return x;
    
    long long int low = 1, high = x - 1, mid, res = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid*mid == x) {
            return mid;
        } else if (mid*mid > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
            res = mid;
        }
    }
    
    return res;
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends