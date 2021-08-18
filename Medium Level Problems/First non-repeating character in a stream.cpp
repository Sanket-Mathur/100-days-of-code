// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> count(26, 0);
		    queue<char> last;
		    string result = "";
		    
		    for (int i = 0; i < A.size(); ++i) {
		        count[(int)A[i] - 97]++;
		        last.push(A[i]);
		        
		        while (!last.empty() && count[(int)last.front() - 97] > 1) {
		            last.pop();
		        }
		        
		        if (last.empty()) {
		            result += '#';
		        } else {
		            result += last.front();
		        }
		    }
		    return result;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends