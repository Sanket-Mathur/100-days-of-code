// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> visited(V, false);
        vector<int> key(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nearest;
        
        key[0] = 0;
        nearest.push(make_pair(0, 0));
        
        while (!nearest.empty()) {
            int u = nearest.top().second;
            nearest.pop();
            
            visited[u] = true;
            for (auto i : adj[u]) {
                if (!visited[i[0]] && i[1] < key[i[0]]) {
                    key[i[0]] = i[1];
                    nearest.push(make_pair(i[1], i[0]));
                }
            }
        }
        
        int cost = 0;
        for (auto i : key) {
            cost += i;
        }
        
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends