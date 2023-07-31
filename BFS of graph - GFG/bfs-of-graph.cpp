//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       
       vector<int>ans;
       vector<int>Vi(V,0);
       
       queue<int>q;
       
       q.push(0);
        
        Vi[0] = 1;
        
        while(!q.empty()){
            int x= q.front();
            q.pop();
            ans.push_back(x);
        
        
        for(auto i: adj[x]){
            if(!Vi[i]){
                q.push(i);
                Vi[i] = 1;
            }
        }
    } 
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends