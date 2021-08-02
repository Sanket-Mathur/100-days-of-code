// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool> visited(V, false);
	    queue<int> verticies;
	    vector<int> bfs;
	    
	    visited[0] = true;
	    verticies.push(0);

	    while (!verticies.empty()) {
	        int current = verticies.front();
	        verticies.pop();
	        
	        bfs.push_back(current);
	        
	        for (auto i : adj[current]) {
	            if (!visited[i]) {
	                verticies.push(i);
	                visited[i] = true;
	            }
	        }
	    }
	    
	    return bfs;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends