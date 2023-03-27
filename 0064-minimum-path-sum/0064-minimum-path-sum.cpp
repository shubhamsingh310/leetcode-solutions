class Solution {
public:
    int dp[201][201];
    int pathSum(vector<vector<int>>& grid, int i, int j){
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int l=INT_MAX,h=INT_MAX;
        if(j+1<grid[0].size())l=pathSum(grid,i,j+1);
        if(i+1<grid.size()) h=pathSum(grid,i+1,j);
        
        dp[i][j]=grid[i][j]+min(l,h);
        
        return dp[i][j];
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return pathSum(grid,0,0);
    }
};