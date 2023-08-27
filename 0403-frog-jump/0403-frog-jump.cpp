class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int dp[2001][2001];

    bool solve(vector<int>& stones, int curr_index, int prev_jump){
        if(curr_index == n-1){
            return true;
        }
        bool res = false;
        if(dp[curr_index][prev_jump]!=-1){
            return dp[curr_index][prev_jump];
        }

        for(int next_jump = prev_jump-1; next_jump<=prev_jump+1; next_jump++){
            if(next_jump > 0){
                int next_stone = stones[curr_index] + next_jump;

                if(mp.find(next_stone)!=mp.end()){
                    res = res || solve(stones, mp[next_stone], next_jump);
                }
            }
        }
        return dp[curr_index][prev_jump] = res;
    }

    bool canCross(vector<int>& stones) {
       n = stones.size();

       if(stones[1]!=1){
           return false;
       }

        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        memset(dp, -1, sizeof(dp));
       return solve(stones,0, 0);
    }
};