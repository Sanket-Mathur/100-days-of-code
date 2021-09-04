// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int maxEle = *max_element(arr, arr+N);
        vector<int> counter(maxEle+1, 0);
        
        for (int i = 0; i < N; ++i) {
            counter[arr[i]]++;
        }
        
        int maxCons = 0, curr = 0;
        for (int i = 0; i <= maxEle; ++i) {
            if (counter[i]) {
                curr++;
            } else {
                maxCons = max(maxCons, curr);
                curr = 0;
            }
        }
        
        return max(maxCons, curr);
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends