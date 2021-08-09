// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int X = 0, prev = INT32_MIN;
        int newarr[n]; 
        for (int i = 0; i < n; ++i) {
            if (a[i] != prev) {
                prev = a[i];
                newarr[X++] = prev;
            }
        }
        for (int i = 0; i < X; ++i) {
            a[i] = newarr[i];
        }
        return X;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}  // } Driver Code Ends