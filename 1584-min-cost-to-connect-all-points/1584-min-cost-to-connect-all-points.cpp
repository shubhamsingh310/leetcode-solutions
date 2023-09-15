class Solution {
public:
    int minKey(vector<bool>& inMST, vector<int>& key) {
        int minIndex = 0;
        int minVal   = INT_MAX;
        for(int i = 0; i<key.size(); i++) {
            if(!inMST[i] && key[i] < minVal) {
                minIndex = i;
                minVal   = key[i];
            }
        }
        return minIndex;
    }
    int MST(vector<vector<int>>& graph, int V) {
        vector<int>  key(V, INT_MAX);
        vector<bool> inMST(V, false);
        key[0] = 0;
        
        for(int count = 1; count<=V-1; count++) {
            int u    = minKey(inMST, key);
            inMST[u] = true;
            
            for(int v = 0; v<V; v++) {
                if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                }
            }
        }
        
        int cost = 0;
        for(int i : key) {
            cost +=i;
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n));
        
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                vector<int> p1 = points[i];
                vector<int> p2 = points[j];
                int md         = abs(p1[0]-p2[0]) + abs(p1[1] - p2[1]);
                graph[i][j]    = md;
                graph[j][i]    = md;
            }
        }
        
        return MST(graph, n);
    }
};