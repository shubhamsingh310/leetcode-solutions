//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dijkstra(int src, vector<pair<int, int>> adj[], vector<int> &dist) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int wt = p.first, u = p.second;
            for(auto i: adj[u]) {
                int v = i.first, w = i.second;
                if(w + wt < dist[v]) {
                    dist[v] = w + wt;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[n + 1];
        vector<vector<int>> curvedEdges;
        
        for(auto i: edges) {
            int u = i[0], v = i[1], w1 = i[2], w2 = i[3];
            adj[u].push_back({v, w1});
            adj[v].push_back({u, w1});
            
            curvedEdges.push_back({u, v, w2});
        }
        
        vector<int> dist1(n + 1, 1e9), dist2(n + 1, 1e9);
        dijkstra(a, adj, dist1);
        dijkstra(b, adj, dist2);
        
        int ans = dist1[b];
        for(int i = 0; i < m; i++) {
            int u = curvedEdges[i][0];
            int v = curvedEdges[i][1];
            int wt = curvedEdges[i][2];
            
            ans = min(ans, dist1[u] + wt + dist2[v]);
            ans = min(ans, dist1[v] + wt + dist2[u]);
        }
        
        return ans >= 1e9 ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends