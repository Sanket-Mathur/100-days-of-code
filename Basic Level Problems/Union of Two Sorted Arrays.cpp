// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int p1 = 0, p2 = 0;
        vector<int> res;
        
        while (p1 < n && p2 < m) {
            if (res.size() > 0 && res[res.size() - 1] == arr1[p1]) {
                p1++;
            } else if (res.size() > 0 && res[res.size() - 1] == arr2[p2]) {
                p2++;
            } else if (arr1[p1] == arr2[p2]) {
                res.push_back(arr1[p1]);
                p1++;
                p2++;
            } else if (arr1[p1] < arr2[p2]) {
                res.push_back(arr1[p1]);
                p1++;
            } else {
                res.push_back(arr2[p2]);
                p2++;
            }
        }
        while (p1 < n) {
            if (res.size() == 0 || res[res.size() - 1] != arr1[p1])
                res.push_back(arr1[p1]);
            p1++;
        }
        while (p2 < m) {
            if (res.size() == 0 || res[res.size() - 1] != arr2[p2])
                res.push_back(arr2[p2]);
            p2++;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends