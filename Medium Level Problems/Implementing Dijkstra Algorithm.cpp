// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<vector<int>> graph(V, vector<int>(V, 0));
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                graph[i][adj[i][j][0]] = adj[i][j][1];
            }
        }
        
        vector<bool> visited(V, false);
        vector<int> distance(V, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> neighbors;
        
        distance[S] = 0;
        neighbors.push(pair<int, int> (0, S));
        
        while (!neighbors.empty()) {
            int current = neighbors.top().second;
            neighbors.pop();
            
            visited[current] = true;
            for (int i = 0; i < V; ++i) {
                if (graph[current][i] != 0 && !visited[i]) {
                    if (distance[i] > distance[current] + graph[current][i]) {
                        distance[i] = distance[current] + graph[current][i];
                        neighbors.push(pair<int, int> (distance[i], i));
                    }
                }
            }
        }
        
        return distance;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends