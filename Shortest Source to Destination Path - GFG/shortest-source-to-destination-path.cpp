//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isValid(int i, int j, int N, int M){
        if(i>=0 && i<N && j>=0 && j<M){
            return true;
        }
        return false;
    };
    
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<bool>> vis(N, vector<bool>(M,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = true;
        
        int steps = 0;
    
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i==X && j==Y){
                    return steps;
                }
                
                //up
                if(isValid(i-1,j,N,M) && A[i-1][j] == 1 && !vis[i-1][j]){
                    vis[i-1][j] = true;
                    q.push({i-1,j});
                }
                
                //down
                 if(isValid(i+1,j,N,M) && A[i+1][j] == 1 && !vis[i+1][j]){
                    vis[i+1][j] = true;
                    q.push({i+1,j});
                }
                
                 if(isValid(i,j-1,N,M) && A[i][j-1] == 1 && !vis[i][j-1]){
                    vis[i][j-1] = true;
                    q.push({i,j-1});
                }
                
                 if(isValid(i,j+1,N,M) && A[i][j+1] == 1 && !vis[i][j+1]){
                    vis[i][j+1] = true;
                    q.push({i,j+1});
                }
            }
            
            steps++;
        }
            return -1;
    
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends