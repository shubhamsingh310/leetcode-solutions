class Solution {
public:
    int dp[99999][2];

    // Function to solve the problem recursively
    int solve(vector<int> &prices, int fee, int itr, int hold) {
        if (itr >= prices.size()) return 0;
        if (dp[itr][hold] != -1) return dp[itr][hold];
        int ans = 0;

        // Checking if current stock is on hold or not
        if (hold)
            ans = max({ans, solve(prices, fee, itr + 1, hold), solve(prices, fee, itr + 1, 0) + prices[itr] - fee});
        else
            ans = max({ans, solve(prices, fee, itr + 1, hold), solve(prices, fee, itr + 1, 1) - prices[itr]});
        return dp[itr][hold] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(prices, fee, 0, 0);
        return ans;
    }
};