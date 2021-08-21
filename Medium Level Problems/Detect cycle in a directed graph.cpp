// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false);
	    vector<bool> ansestor(V, false);
	    
	    for (int i = 0; i < V; ++i) {
	        if (!visited[i] && dfs(adj, V, visited, i, ansestor))
	            return true;
	    }
	    
	    return false;
	}
	bool dfs(vector<int> adj[], int V, vector<bool> &visited, int start, vector<bool> &ansestor) {
	    visited[start] = true;
	    ansestor[start] = true;
	    
	    for (auto node : adj[start]) {
	        if (!visited[node] && dfs(adj, V, visited, node, ansestor)) {
	                return true;
	        } else if (ansestor[node]) {
	            return true;
	        }
	    }
	    ansestor[start] = false;
	    return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends