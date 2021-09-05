// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    stack<int> nodes;

        for (int v = 0; v < V; ++v) {
            if (color[v] == -1) {
                color[v] = 0;
                nodes.push(v);
                
                while (!nodes.empty()) {
                    int top = nodes.top();
        	        nodes.pop();
        	        
        	        for (int i : adj[top]) {
        	            if (color[i] == color[top]) {
        	                return false;
        	            } else if (color[i] == -1) {
        	                nodes.push(i);
        	            }
        	            
        	            color[i] = color[top] == 0 ? 1 : 0;
        	        }
        	    }
            }
        }
	    

	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends