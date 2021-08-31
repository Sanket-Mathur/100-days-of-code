// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    pair<int, int> arrPos[nums.size()];
	    for (int i = 0; i < nums.size(); ++i) {
	        arrPos[i] = make_pair(nums[i], i);
	    }
	    sort(arrPos, arrPos + nums.size());
	    
	    vector<bool> visited(nums.size(), false);
	    int result = 0;
	    
	    for (int i = 0; i < nums.size(); ++i) {
	        if (visited[i] || arrPos[i].second == i)
	            continue;
	        
	        int cyclesize = 0;
	        int j = i;
	        while (!visited[j]) {
	            visited[j] = true;
	            j = arrPos[j].second;
	            cyclesize++;
	        }
	        
	        if (cyclesize)
	            result += cyclesize - 1;
	    }
	    
	    return result;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends