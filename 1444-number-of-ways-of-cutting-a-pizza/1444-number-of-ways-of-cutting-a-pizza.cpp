class Solution {
    bool good(vector<string> &pizza, int r1, int c1, int r2, int c2) {
        for(int i=r1; i<r2; i++) {
            for(int j=c1; j<c2; j++) {
                if(pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    int dfs(int i, int j, int k, int n, int m, vector<string> &pizza, int mod, vector<vector<vector<int>>> &dp) {
        if(!k) return good(pizza, i, j, n, m);
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ans = 0;
        for(int h=i+1; h<n; h++) {
            if(good(pizza, i, j, h, m)) {
                ans = (ans + dfs(h, j, k - 1, n, m, pizza, mod, dp)) % mod;
            }
        }
        for(int v=j+1; v<m; v++) {
            if(good(pizza, i, j, n, v)) {
                ans = (ans + dfs(i, v, k - 1, n, m, pizza, mod, dp)) % mod;
            }
        }
        return dp[i][j][k] = ans;
    }
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size(), mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return dfs(0, 0, k - 1, n, m, pizza, mod, dp);
    }
};