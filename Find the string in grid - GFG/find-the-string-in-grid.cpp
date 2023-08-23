//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    //directional array
    
	int dx[8] = {-1,0,1,0,1,1,-1,-1};
    int dy[8] = {0,-1,0,1,1,-1,1,-1};
    
    bool dfs(int i,int j,int dir_x,int dir_y,vector<vector<char>>&grid,int start,string word) {
        if(start>=word.length()){
            return true;
        }
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }
        
        if(grid[i][j] == word[start]) {
            return dfs(i+dir_x, j+dir_y, dir_x, dir_y, grid, start+1, word);
        } else {
            return false;
        }
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	   vector<vector<int>>ans;
	   int rows = grid.size();
	   int cols = grid[0].size();
	   for(int i=0;i<rows;i++){
	       for(int j=0;j<cols;j++){
	           if(grid[i][j] == word[0]) {
	               for(int k=0;k<8;k++) {
	                   if(dfs(i+dx[k],j+dy[k],dx[k],dy[k],grid,1,word)) {
	                        ans.push_back({i,j});
	                        break;
	                   }
	               }
	           }
	       }
	   }
	   return ans;
	}
};



        // {{a,b,c}
        // {d,r,f}         a b c
        // {g,h,i}

        
        //  {a,b,a,b} 
        //  {a,b,e,b}      a b e
        //  {e,b,e,b}
         
         

        


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends