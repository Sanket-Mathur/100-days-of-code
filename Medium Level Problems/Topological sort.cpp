// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> result;
	    vector<int> indegree(V, 0);
	    queue<int> possible;
	    
	    for (int i = 0; i < V; ++i) {
	        for (auto v : adj[i]) {
	            indegree[v]++;
	        }
	    }
	    
	    for (int i = 0; i < V; ++i) {
	        if (!indegree[i])
	            possible.push(i);
	    }
	    
	    while (!possible.empty()) {
	        int v = possible.front();
	        possible.pop();
	        result.push_back(v);
	        
	        for (auto i : adj[v]) {
	            indegree[i]--;
	            if (!indegree[i])
	                possible.push(i);
	        }
	    }
	    
	    return result;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends